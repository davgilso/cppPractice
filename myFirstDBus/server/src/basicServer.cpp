#include <iostream>
#include <memory>
#include <string>

#include <dbus/dbus.h>

class fooDbusConnection{

private:
	//Value and pointer constant.
	DBusConnection* connection;
	const char *name = "dav.cpp.practice.server";

	void messageListener(void)
	{
		// loop, testing for new messages
   		while (true) 
		{
	  		// non blocking read of the next available message
      		dbus_connection_read_write(connection, 0);
      		msg = dbus_connection_pop_message(connection);

			// loop again if we haven't got a message
      		if (NULL == msg) 
			{ 
         		sleep(1); 
         		continue; 
      		}

      		// check this is a method call for the right interface and method
    		if (dbus_message_is_method_call(msg, "dav.cpp.practice.server", "Method"))
				reply_to_method_call(msg, connection);
			{
			}
			
			// free the message
      		dbus_message_unref(msg);
   		}
	}

	void reply_to_method_call(DBusMessage* msg, DBusConnection* conn)
	{
		DBusMessage* reply;
		DBusMessageIter args;
		DBusConnection* conn;
		
		bool stat = true;
		
		dbus_uint32_t level = 21614;
		dbus_uint32_t serial = 0;
		
		char* param = "";

		// read the arguments
		if (!dbus_message_iter_init(msg, &args))
		{
			std::cout << "Message has no arguments!\n"; 
		}
		else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args)) 
		{
			fprintf(stderr, "Argument is not string!\n"); 
		}
		else
		{ 
			dbus_message_iter_get_basic(&args, &param);
		}

		printf("Method called with %s\n", param);

		// create a reply from the message
		reply = dbus_message_new_method_return(msg);

		// add the arguments to the reply
		dbus_message_iter_init_append(reply, &args);
		if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_BOOLEAN, &stat)) 
		{ 
			fprintf(stderr, "Out Of Memory!\n"); 
			exit(1);
		}
		if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_UINT32, &level)) 
		{
			fprintf(stderr, "Out Of Memory!\n"); 
			exit(1);
		}

		// send the reply && flush the connection
		if (!dbus_connection_send(conn, reply, &serial)) 
		{ 
			fprintf(stderr, "Out Of Memory!\n"); 
			exit(1);
		}
		
		dbus_connection_flush(conn);

		// free the reply
		dbus_message_unref(reply);
	}

	
	int reserverDbusName()
	{
		DBusError error;
		
		dbus_error_init(&error); /* Initialize the error structure */
		
		dbus_bool_t ret = dbus_bus_name_has_owner(connection, name, &error);
		
		if (dbus_error_is_set(&error))
		{
			std::cout <<"Error reserving name: " << error.message << std::endl;
			dbus_error_free(&error);
			return 1;
		}
		
		if (ret)
		{
			std::cout << "Bus name already registered!" << std::endl;
			return 1;
		}
		else
		{
			std::cout <<"Bus name " << name << " doesn't have an owner, reserving it..." << std::endl;

			int request_name_reply = dbus_bus_request_name(connection, name, DBUS_NAME_FLAG_DO_NOT_QUEUE, &error);

			if ( dbus_error_is_set(&error) )
			{
				dbus_error_free(&error);
				std::cout << "Error requesting a bus name: " << error.message << std::endl;
				return 1;
			}
			else if ( request_name_reply == DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER )
			{
				std::cout <<"Bus name Successfully reserved!" << std::endl;
				return 0;
			}
			else
			{
				std::cout << "Failed to reserve name" << std::endl;
				return 1;
			}
		}
	}

public:

	fooDbusConnection()
	{
		DBusError error;
		
		dbus_error_init(&error); /* Initialize the error structure */
		
		connection = dbus_bus_get(DBUS_BUS_SESSION,&error); /* Or DBUS_BUS_SYSTEM */
		
		if (dbus_error_is_set(&error))
		{
			std::cout <<"Error connecting to the daemon bus " << error.message << std::endl;
			dbus_error_free(&error);
		}
		else
		{
			reserverDbusName();
		}
	}

	~fooDbusConnection()
	{
		dbus_connection_close(connection);
	}
	
	const DBusConnection* const getConnection()
	{
		return connection;
	}
	
};

int main()
{
	fooDbusConnection myDbusConnection;
	
	std::cin.get();
	return 0;
}