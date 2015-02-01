#include<iostream>
using namespace std;

class stp
{
public:
    typedef enum {fk,ack} frame_kind;
    typedef enum {frame_arrive,frame_send,waiting} event_type;
    typedef struct
    {
        char data[10];
    } packet;
    typedef struct
    {
        frame_kind kind;
        packet info;
    } frame;
    event_type current_event;
    frame *medium;

    void wait_for_event(event_type *event)
    {
        *event=waiting;
    }

    void from_network_layer(packet *p)
    {
        cout<<"Enter the data to be send from Application Layer to Network Layer : ";
        cin>>p->data;
    }

    void to_physical_layer(frame *s)
    {
        cout<<"\nSending frame to Physical Layer............\n";
        medium=s;
    }

    void from_physical_layer(frame *f)
    {
        cout<<"\nReceiving Data from physical layer...........\n";
        f=medium;
    }

    void to_network_layer(packet *p)
    {
        cout<<"\nData received from network layer to application layer :";
       cout<< p->data<<"\n";
	 }

    void sender()
    {
        frame s;
        packet p;
        current_event=frame_send;
        while(current_event!=waiting)
        {
            from_network_layer(&p);
            s.info=p;
            to_physical_layer(&s);
            wait_for_event(&current_event);
        }
    }

    void receiver()
    {
        frame r,s;
        current_event=frame_arrive;
        while(current_event!=waiting)
        {
            wait_for_event(&current_event);
            from_physical_layer(&r);
            to_network_layer(&r.info);
            cout<<"\nSending dummy frames..........\n";
            to_physical_layer(&s);
        }
    }

};
int main()
{
    cout<<"Data Transmission Started.................................................\n";
    stp d1;
    d1.sender();
    d1.receiver();
    return 0;
}
