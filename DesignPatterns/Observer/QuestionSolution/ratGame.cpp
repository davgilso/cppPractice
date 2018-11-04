#include <iostream>
#include <vector>

using namespace std;

struct IRat //Observable
{
    //NotifyEnterRat
    virtual void enterRat(IRat *rat) = 0;
    virtual void killRat() = 0;
    virtual void notify(IRat *rat) = 0;
};

struct Game //Observer
{
    vector<IRat *>ratSwarm;

    void notifyEnterRat(IRat *newRat)
    {
        for (auto rat : ratSwarm)
        {
            rat->enterRat(newRat);
        }
    }

    void notifyKillRat()
    {
        for (auto rat : ratSwarm)
        {
            rat->killRat();
        }
    }

    void notifyAttackIncrease(IRat *newRat)
    {
        for(auto rat : ratSwarm)
        {
            rat->notify(newRat);
        }
    }
};

struct Rat : IRat //Observable
{
    Game& game;
    int attack{1};

    Rat(Game &game) : game(game)
    {
      game.ratSwarm.push_back(this);
      game.notifyEnterRat(this);
      
    }

    void enterRat(IRat *newRat) override
    {
        if (newRat != this)
        {
            ++attack;
            game.notifyAttackIncrease(newRat);
            
        }
    }

    void killRat() override
    {
        --attack;
    }

    void notify(IRat *newRat) override
    {
        if (newRat == this)
        {
            ++attack;
        }
    }

    ~Rat() 
    { 
        // rat dies here!
        game.notifyKillRat();
    }
};
