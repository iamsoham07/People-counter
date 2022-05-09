import processing.serial.*;

Serial port;
int val;
int count=0;
PFont f;                           // STEP 1 Declare PFont variable

void setup()  {
    size(400,400);
    noStroke();
    println(Serial.list());  // print list of available serial port 
    port=new Serial(this,Serial.list()[0],9600);        
    f = createFont("Arial",16,true); // STEP 2 Create Font
 }
  
void draw()  {
  if(0<port.available())
  {
    val=port.read();
  } 
    background(204);
    println(val);

  if(val==48)
{     fill(255,0,0);   // red
  rect(50,50,300,300);  // green
}
  else if(val==49)
{     fill(0,255,0);   // green
  rect(50,50,300,300);  // green
  count++;
}

  textFont(f,30);               
  fill(0);                         
  text("Number of Person is: " + count , 30, 30);
//text(count, 100, 100);
delay(100);

 }

/* END OF CODE */
