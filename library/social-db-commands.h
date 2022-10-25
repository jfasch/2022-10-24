#pragma once

#include <variant>


class SocialDBCommand
{
public:
    virtual ~SocialDBCommand() {}
    virtual void execute(SocialDB&) = 0;
};

class SocialDBInsertCommand : public SocialDBCommand
{
public:
    SocialDBInsertCommand(
        const std::string& svnr, 
        const std::string& firstname, 
        const std::string& lastname)
    : _svnr(svnr),
      _firstname(firstname),
      _lastname(lastname),
      _notinserted("") {}

    void execute(SocialDB& db) override
    {
        try {
            db.insert(_svnr, _firstname, _lastname);
        }
        catch (const SocialDB::NotInserted& notinserted) {
            _notinserted = notinserted;
        }
    }

    void result() 
    {
        if (_notinserted)
            throw _notinserted.value();
    }

private:
    const std::string _svnr;
    const std::string _firstname;
    const std::string _lastname;

    std::optional<SocialDB::NotInserted> _notinserted;
};

class SocialDBFindCommand : public SocialDBCommand
{
public:
    SocialDBFindCommand(const std::string& svnr) : _svnr(svnr) {}

    void execute(SocialDB& db) override
    {
        try {
            _result = db.find(_svnr);
        }
        catch (const SocialDB::NotFound& notfound) {
            _result = notfound;
        }
    }

    SocialDB::Person result()
    {
        if (std::holds_alternative<SocialDB::Person>(_result))
            return std::get<SocialDB::Person>(_result);
        else
            throw std::get<SocialDB::NotFound>(_result);
    }

private:
    const std::string _svnr;
    std::variant<SocialDB::Person, SocialDB::NotFound> _result;
};

class SocialDBDropCommand : public SocialDBCommand
{
public:
    void execute(SocialDB& db) override
    {
        db.drop();
    }

    void result() {}
};

