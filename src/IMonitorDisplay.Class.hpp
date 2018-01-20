#ifndef IMONITORDISPLAY_H
#define IMONITORDISPLAY_H

class IMonitorDisplay {
    private:
	public:
        IMonitorDisplay ();
        IMonitorDisplay (IMonitorDisplay const &cc);
        ~IMonitorDisplay ();
        IMonitorDisplay &operator=(IMonitorDisplay const &input);
        virtual void run(void) = 0;
        virtual void config(void) = 0;
};
#endif
