#include <iostream>

class Monitor 
{
	int brightness = 80;
	int resolution = 1920;
public:
	void set_brightness(int value) { brightness = value; }
	void set_resolution(int value) { resolution = value; }

	int get_brightness() const { return brightness;}
	int get_resolution() const { return resolution;}
};
