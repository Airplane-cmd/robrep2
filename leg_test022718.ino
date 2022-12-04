#include <Servo.h>
//#include <array>
int n = 8;
Servo *arr = new Servo[n];
int sitUAng{60};
int sitLAng{60};
int standUAng{90};
int standLAng{90};
int stepUAng{75};
int stepLAng{75};
//Servo upper{*arr[0]};
void rotate(int degrees = 1);
class machine;
class leg
{
private:
	Servo m_upper;
	Servo m_lower;
public:
	leg(Servo &upper, Servo &lower) : m_upper{upper}, m_lower{lower}{};
	friend class machine;
	void stand()
    	{
      		for(int i = sitLAng; i < standLAng; ++i)
      		{
        		this->m_lower.write(i);
        		delay(20);
      		}
      		for(int i = sitUAng; i < standUAng; ++i)
      		{
        		this->m_upper.write(i);
        		delay(20);
      		}
    	}
    	void sit();
    	void step();    
};
class machine:
{
private:
	leg m_fl;
	leg m_fr;
	leg m_bl;
	leg m_br;
public:
	machine(leg &fl, leg &fr, leg &bl, leg &br) : m_fl{fl}, m_fr{fr}, m_bl{bl}, m_br{br}{};
	leg& getFl() 
    	{
      		return m_fl;
    	}
    	leg& getFr() 
    	{
      		return m_fr;
    	} 
    	leg& getBl() 
    	{
      		return m_bl;
    	}
    	leg& getBr() 
    	{
      		return m_br;
    	}
    	void stand(leg &leg1, leg &leg2)//stand
    	{
      		for(int i = sitLAng; i < standLAng; ++i)
      		{
        		leg1.m_lower.write(i);
        		leg2.m_lower.write(i);
        		delay(20);
		}
      		for(int i = sitUAng; i < standUAng; ++i)
		{
        		leg1.m_upper.write(i);
        		leg2.m_upper.write(i);
        		delay(20);
      		}
	}
	void stand()
    	{
      		for(int i = sitLAng; i < standLAng; ++i)
      		{
        		m_fl.m_lower.write(i);
        		m_fr.m_lower.write(i);
			m_bl.m_lower.write(i);
			m_br.m_lower.write(i);
        		delay(20);
		}
      		for(int i = sitUAng; i < standUAng; ++i)
		{
			m_fl.m_upper.write(i);
        		m_fr.m_upper.write(i);
			m_bl.m_upper.write(i);
			m_br.m_upper.write(i);
 
        		delay(20);
      		}
	}
	void stand(leg &leg1, leg &leg2, leg &leg3)
	{
		for(int i = sitLAng; i < standLAng; ++i)
      		{
        		leg1.m_lower.write(i);
        		leg2.m_lower.write(i);
			leg3.m_lower.write(i);
        		delay(20);
		}
      		for(int i = sitUAng; i < standUAng; ++i)
		{
        		leg1.m_upper.write(i);
        		leg2.m_upper.write(i);
			leg3.m_upper.write(i);
        		delay(20);
      		}
	}	
	void sit(leg &leg1, leg &leg2)//sit
    	{
      		for(int i = standLAng; i > sitLAng; --i)
      		{
        		leg1.m_lower.write(i);
        		leg2.m_lower.write(i);
        		delay(20);
		}
      		for(int i = sitUAng; i > standUAng; ++i)
		{
        		leg1.m_upper.write(i);
        		leg2.m_upper.write(i);
        		delay(20);
      		}
	}
	void sit()
    	{
      		for(int i = standLAng; i > sitLAng; --i)
      		{
        		m_fl.m_lower.write(i);
        		m_fr.m_lower.write(i);
			m_bl.m_lower.write(i);
			m_br.m_lower.write(i);
        		delay(20);
		}
      		for(int i = standUAng; i > sitUAng; --i)
		{
			m_fl.m_upper.write(i);
        		m_fr.m_upper.write(i);
			m_bl.m_upper.write(i);
			m_br.m_upper.write(i);
        		delay(20);
      		}
	}
	void sit(leg &leg1, leg &leg2, leg &leg3)
	{
		for(int i = standLAng; i > standLAng; --i)
      		{
        		leg1.m_lower.write(i);
        		leg2.m_lower.write(i);
			leg3.m_lower.write(i);
        		delay(20);
		}
      		for(int i = standUAng; i > standUAng; --i)
		{
        		leg1.m_upper.write(i);
        		leg2.m_upper.write(i);
			leg3.m_upper.write(i);
        		delay(20);
      		}
	}
	void step(leg &leg1, leg &leg2)//step
	{
		for(int i = sitLAng; i < stepLAng; ++i)
      		{
        		leg1.m_lower.write(i);
        		leg2.m_lower.write(i);
        		delay(20);
		}
      		for(int i = sitUAng; i < stepUAng; ++i)
		{
        		leg1.m_upper.write(i);
        		leg2.m_upper.write(i);
        		delay(20);
      		}
	
	}
	void step(leg &leg1)
	{
		for(int i = sitLAng; i < stepLAng; ++i)
      		{
        		leg1.m_lower.write(i);
        		delay(20);
		}
      		for(int i = sitUAng; i < sitUAng; ++i)
		{
        		leg1.m_upper.write(i);
        		delay(20);
      		}
	}

    	void correct(){};
    	void walk2()
    	{
        	this->stand(m_fr, m_bl);//sit->step
		this->step(m_fl, m_br);
		this->sit(m_fr, m_bl);
		this->stand(m_fl, m_br);
		this->step(m_fr, m_bl);
		this->sit(m_fl, m_br);
    	}
    	void walk1()
    	{
		this->stand(m_fr, m_bl, m_br);
		this->step(m_fl);
		this->sit(m_fr, m_bl, m_br);
		this->stand(m_fl, m_fr, m_bl);
		this->step(m_br);
		this->sit(m_fl, m_fr, m_bl);
		this->stand(m_fl, m_br, m_bl);
		this->step(m_fr);
		this->sit(m_fl, m_fr, m_bl);
		this->stand(m_fl, m_fr, m_br);
		this->step(m_bl);
		this->sit(m_fl, m_fr, m_bl);
	};
};
leg leg1(arr[0], arr[1]);
leg leg2(arr[2], arr[3]);
leg leg3(arr[4], arr[5]);
leg leg4(arr[6], arr[7]);
machine spot(leg1, leg2, leg3, leg4);
void setup() 
{
	Serial.begin(9600);
  	for(int i = 0; i < n; i++)
  	{
    		arr[i].attach(i+2);  
  	}
  	delay(1000);
	spot.sit();

}

void loop() 
{
//  rotate();
  spot.walk2();        
}
void rotate(int degrees = 1)
{
  int pos{0};
  for (pos = 0; pos <= 180; pos += degrees) 
  {
    for(int i = 0; i < n; ++i)  arr[i].write(pos);
    delay(15);                         
  }
  for (pos = 180; pos >= 0; pos -= degrees)
  {
    for(int i = 0; i < n; ++i)  arr[i].write(pos);
    delay(15);                       
  }
      
}
