float temp;
int flag[10];
int tempPin = 0;
float m=0,d=0,g=0,u=0,b=0,w=0;
int time=5000;
int sum=0;
//void predict(int temp);
//void disp();
void setup()
{
  Serial.begin(9600);
}

void loop()
{  
  /*temp = analogRead(tempPin);
  temp = temp * 0.48828125;
  Serial.print("TEMPRATURE = ");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  delay(1000);*/
  if(time>0)
  {
  //predict(temp);
        temp = analogRead(tempPin);
        temp = temp * 0.48828125;
        temp=temp+13;
        Serial.print("TEMPRATURE = ");
        Serial.print(temp);
        Serial.print("*C");
        Serial.println();
        delay(1000);
        if(temp>=38)
	{
		m=m+1;
               if(temp>=40)
                {
                d=d+1;
                m=m-1;
                }
                else if(temp>=41)
                {
                g=g+1;
                m=m-1;
                d=d-1;
                }
                
	}
	else if(temp>37 && temp<=38)
	{
		u=u+1;  
	}
        else if(temp<=35)
        {
          b=b+1;
          if(temp<=32 && temp>=28)
          w=w+1;
          b=b-1;
        }
  }
  else if(time==0)
  {
  //disp();
        float percent;
        int sum;
        sum=m+d+w+b+u+g;
        /*Serial.print(m);
        Serial.println();
        Serial.print(t);
        Serial.println();*/
        Serial.print("Prediction");
	Serial.println();
   	percent=((m/(sum))*100);
	Serial.print("Malaria:");
	Serial.print(percent);
        Serial.print("%");
	Serial.println();
	percent=((d/(sum))*100);
	Serial.print("Dengue/Chikungunya:");
	Serial.print(percent);
        Serial.print("%");
	Serial.println();
	percent=((g/(sum))*100);
        Serial.print("Giardiasis:");
	Serial.print(percent);
        Serial.print("%");
	Serial.println();
	percent=((u/(sum))*100);
        Serial.print("Urinary Tract Infection:");
	Serial.print(percent);
        Serial.print("%");
	Serial.println();
	percent=((b/(sum))*100);
        Serial.print("Bacterial infection:");
	Serial.print(percent);
        Serial.print("%");
	Serial.println();
	percent=((w/(sum))*100);
        Serial.print("Wilson's disease:");
	Serial.print(percent);
        Serial.print("%");
	Serial.println();
        if(m==0 && d==0 && g==0 && u==0 && b==0 && w==0)
        {
          Serial.print("Everthing normal bro");
        }

  }
  else if(time<0)
  {
    time=6000;
    m=0;
    d=0;
    g=0;
    u=0;
    b=0;
    w=0;
    delay(1000000000);
    /*Serial.print("End");
    Serial.println();*/
    
  }
  time=time-250;
  
}
