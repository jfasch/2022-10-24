#pragma once

#include "social-db.h"

class SocialDB_Observable : public SocialDB
{
public:
    class NewCitizenObserver
    {
    public:
        virtual ~NewCitizenObserver() {}
        virtual void new_citizen_added(const std::string& svnr) = 0;
    };

    class ObserverAlreadyRegistered : public std::exception {};
    class ObserverNotRegistered : public std::exception {};

public:
    void register_new_citizen_notification(NewCitizenObserver* o)
    {
        if (_observers.find(o) != _observers.end())
            throw ObserverAlreadyRegistered();
        _observers.insert(o);
    }

    void unregister_new_citizen_notification(NewCitizenObserver* o)
    {
        auto found = _observers.find(o);
        if (found == _observers.end())
            throw ObserverNotRegistered();
        _observers.erase(found);
    }

    void insert(const std::string& svnr, const std::string& firstname, const std::string& lastname)
    {
        SocialDB::insert(svnr, firstname, lastname);
        for (auto o: _observers)
            o->new_citizen_added(svnr);
    }

private:
    std::set<NewCitizenObserver*> _observers;
};
