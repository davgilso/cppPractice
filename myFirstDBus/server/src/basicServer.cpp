#include <iostream>
#include <memory>
#include <string>

#include <dbus/dbus.h>

class fooDbusConnection{

private:
	//Value and pointer constant.
	DBusConnection* connection;
	const char *name = "dav.cpp.practice";
	
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