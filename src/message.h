#ifndef TANAKA_MESSAGE_H_
#define TANAKA_MESSAGE_H_

namespace Tanaka
{

enum MessageType
{
    MSG_Move
};

class Message
{
public:
    Message(int type):_type(type){}

    int type() {return _type;}

private:
    int _type;
};

} //end namespace Tanaka

#endif
