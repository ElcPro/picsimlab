/* ########################################################################

   PICsimLab - PIC laboratory simulator

   ########################################################################

   Copyright (c) : 2015-2018  Luis Claudio Gambôa Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */

//include files
#include"../picsimlab1.h"
#include"../picsimlab4.h" //Oscilloscope
#include"../picsimlab5.h" //Spare Parts
#include"board_5.h"

#ifdef _WIN_
HANDLE avr_serial_get_fd(void);
#else
int avr_serial_get_fd(void);
#endif

/* ids of inputs of input map*/
#define I_ICSP	1  //ICSP connector
#define I_PWR	2  //Power button
#define I_RST	3  //Reset button


/* ids of outputs of output map*/
#define O_L	1  //switch position (On/Off)
#define O_RX	2  //LED on RD0 push button
#define O_TX	3  //LED on RD1 switch
#define O_ON	4  //Power LED

//return the input ids numbers of names used in input map
unsigned short 
cboard_5::get_in_id(char * name)
{
  if(strcmp(name,"I_ICSP")==0)return I_ICSP;
  if(strcmp(name,"I_PWR")==0)return I_PWR;  
  if(strcmp(name,"I_RST")==0)return I_RST; 
  
  printf("Erro input '%s' don't have a valid id! \n",name);
  return -1;
};

//return the output ids numbers of names used in output map
unsigned short 
cboard_5::get_out_id(char * name)
{ 
    
  if(strcmp(name,"O_L")==0)return O_L;
  if(strcmp(name,"O_TX")==0)return O_TX;
  if(strcmp(name,"O_RX")==0)return O_RX;
  if(strcmp(name,"O_ON")==0)return O_ON;
  
  printf("Erro output '%s' don't have a valid id! \n",name);
  return 1;
};

//Constructor called once on board creation 
cboard_5::cboard_5(void)
{
  //FIXME
  proc="atmega328";  //default microcontroller if none defined in preferences
  ReadMaps();     //Read input and output board maps

  //controls propierties and creation

  //gauge1
  gauge1=new CGauge();
  gauge1->SetFOwner(&Window1);
  gauge1->SetName(wxT("gauge1_p7"));
  gauge1->SetX(35);
  gauge1->SetY(205);
  gauge1->SetWidth(110);
  gauge1->SetHeight(20);
  gauge1->SetEnable(1);
  gauge1->SetVisible(1);
  gauge1->SetRange(100);
  gauge1->SetValue(0);
  gauge1->SetType(4);
  Window1.CreateChild(gauge1);
  //gauge2
  gauge2=new CGauge();
  gauge2->SetFOwner(&Window1);
  gauge2->SetName(wxT("gauge2_p7"));
  gauge2->SetX(35);
  gauge2->SetY(230);
  gauge2->SetWidth(110);
  gauge2->SetHeight(20);
  gauge2->SetEnable(1);
  gauge2->SetVisible(1);
  gauge2->SetRange(100);
  gauge2->SetValue(0);
  gauge2->SetType(4);
  Window1.CreateChild(gauge2);   
  //gauge3
  gauge3=new CGauge();
  gauge3->SetFOwner(&Window1);
  gauge3->SetName(wxT("gauge3_p7"));
  gauge3->SetX(35);
  gauge3->SetY(255);
  gauge3->SetWidth(110);
  gauge3->SetHeight(20);
  gauge3->SetEnable(1);
  gauge3->SetVisible(1);
  gauge3->SetRange(100);
  gauge3->SetValue(0);
  gauge3->SetType(4);
  Window1.CreateChild(gauge3);   
  //gauge4
  gauge4=new CGauge();
  gauge4->SetFOwner(&Window1);
  gauge4->SetName(wxT("gauge4_p7"));
  gauge4->SetX(35);
  gauge4->SetY(280);
  gauge4->SetWidth(110);
  gauge4->SetHeight(20);
  gauge4->SetEnable(1);
  gauge4->SetVisible(1);
  gauge4->SetRange(100);
  gauge4->SetValue(0);
  gauge4->SetType(4);
  Window1.CreateChild(gauge4); 
   //gauge5
  gauge5=new CGauge();
  gauge5->SetFOwner(&Window1);
  gauge5->SetName(wxT("gauge5_p7"));
  gauge5->SetX(35);
  gauge5->SetY(305);
  gauge5->SetWidth(110);
  gauge5->SetHeight(20);
  gauge5->SetEnable(1);
  gauge5->SetVisible(1);
  gauge5->SetRange(100);
  gauge5->SetValue(0);
  gauge5->SetType(4);
  Window1.CreateChild(gauge5);
   //gauge6
  gauge6=new CGauge();
  gauge6->SetFOwner(&Window1);
  gauge6->SetName(wxT("gauge6_p7"));
  gauge6->SetX(35);
  gauge6->SetY(330);
  gauge6->SetWidth(110);
  gauge6->SetHeight(20);
  gauge6->SetEnable(1);
  gauge6->SetVisible(1);
  gauge6->SetRange(100);
  gauge6->SetValue(0);
  gauge6->SetType(4);
  Window1.CreateChild(gauge6);
  
  //label1
  label1=new CLabel();
  label1->SetFOwner(&Window1);
  label1->SetName(wxT("label1_p7"));
  label1->SetX(12);
  label1->SetY(205);
  label1->SetWidth(20);
  label1->SetHeight(20);
  label1->SetEnable(1);
  label1->SetVisible(1);
  label1->SetText(wxT("3"));
  label1->SetAlign(1);
  Window1.CreateChild(label1); 
  //label2
  label2=new CLabel();
  label2->SetFOwner(&Window1);
  label2->SetName(wxT("label2_p7"));
  label2->SetX(12);
  label2->SetY(230);
  label2->SetWidth(20);
  label2->SetHeight(20);
  label2->SetEnable(1);
  label2->SetVisible(1);
  label2->SetText(wxT("5"));
  label2->SetAlign(1);
  Window1.CreateChild(label2);    
  //label3
  label3=new CLabel();
  label3->SetFOwner(&Window1);
  label3->SetName(wxT("label3_p7"));
  label3->SetX(13);
  label3->SetY(255);
  label3->SetWidth(20);
  label3->SetHeight(20);
  label3->SetEnable(1);
  label3->SetVisible(1);
  label3->SetText(wxT("6"));
  label3->SetAlign(1);
  Window1.CreateChild(label3);    
  //label4
  label4=new CLabel();
  label4->SetFOwner(&Window1);
  label4->SetName(wxT("label4_p7"));
  label4->SetX(13);
  label4->SetY(280);
  label4->SetWidth(20);
  label4->SetHeight(20);
  label4->SetEnable(1);
  label4->SetVisible(1);
  label4->SetText(wxT("9"));
  label4->SetAlign(1);
  Window1.CreateChild(label4);  
  //label5
  label5=new CLabel();
  label5->SetFOwner(&Window1);
  label5->SetName(wxT("label5_p7"));
  label5->SetX(13);
  label5->SetY(305);
  label5->SetWidth(20);
  label5->SetHeight(20);
  label5->SetEnable(1);
  label5->SetVisible(1);
  label5->SetText(wxT("10"));
  label5->SetAlign(1);
  Window1.CreateChild(label5);    
  //label6
  label6=new CLabel();
  label6->SetFOwner(&Window1);
  label6->SetName(wxT("label6_p7"));
  label6->SetX(13);
  label6->SetY(330);
  label6->SetWidth(20);
  label6->SetHeight(20);
  label6->SetEnable(1);
  label6->SetVisible(1);
  label6->SetText(wxT("11"));
  label6->SetAlign(1);
  Window1.CreateChild(label6);  
};

//Destructor called once on board destruction 
cboard_5::~cboard_5(void)
{
    //controls destruction 
    Window1.DestroyChild(gauge1);
    Window1.DestroyChild(gauge2);
    Window1.DestroyChild(gauge3);
    Window1.DestroyChild(gauge4);
    Window1.DestroyChild(gauge5);
    Window1.DestroyChild(gauge6);

    Window1.DestroyChild(label1);
    Window1.DestroyChild(label2);
    Window1.DestroyChild(label3);
    Window1.DestroyChild(label4);
    Window1.DestroyChild(label5);
    Window1.DestroyChild(label6);
    
}

//Reset board status
void 
cboard_5::Reset(void)
{
   
    //write button state to pic pin 19 (RD0)
    //pic_set_pin(19,p_BT1); 
    //write switch state to pic pin 20 (RD1)
    //pic_set_pin(20,p_BT2); 

    
  //verify serial port state and refresh status bar  
#ifndef _WIN_
    if(avr_serial_get_fd() > 0)
#else
    if(avr_serial_get_fd() != INVALID_HANDLE_VALUE)
#endif
      Window1.statusbar1.SetField(2,wxT("Serial Port: ")+
        String::FromAscii(SERIALDEVICE)+wxT(":")+itoa(serialbaud)+wxT("(")+
        String().Format("%4.1f",fabs((100.0*serialexbaud-100.0*
        serialbaud)/serialexbaud))+wxT("%)"));
    else  
      Window1.statusbar1.SetField(2,wxT("Serial Port: ")+
        String::FromAscii(SERIALDEVICE)+wxT(" (ERROR)"));
    
/*
  //reset mean value
  for(int pi=0;pi < pic.PINCOUNT;pi++)
  {
    lm[pi]=0;
  };
*/
};

//Called ever 1s to refresh status
void 
cboard_5::RefreshStatus(void)
{
   //verify serial port state and refresh status bar   
#ifndef _WIN_
    if(avr_serial_get_fd() > 0)
#else
    if(avr_serial_get_fd()!= INVALID_HANDLE_VALUE)
#endif
      Window1.statusbar1.SetField(2,wxT("Serial Port: ")+
        String::FromAscii(SERIALDEVICE)+wxT(":")+itoa(serialbaud)+wxT("(")+
        String().Format("%4.1f",fabs((100.0*serialexbaud-100.0*
        serialbaud)/serialexbaud))+wxT("%)"));
    else  
      Window1.statusbar1.SetField(2,wxT("Serial Port: ")+
        String::FromAscii(SERIALDEVICE)+wxT(" (ERROR)"));
};

//Called to save board preferences in configuration file
void 
cboard_5::WritePreferences(void)
{
    //write selected microcontroller of board_x to preferences
    Window1.saveprefs(wxT("p7_proc"),proc);
};

//Called whe configuration file load  preferences 
void 
cboard_5::ReadPreferences(char *name,char *value)
{
    //read microcontroller of preferences
    if(!strcmp(name,"p7_proc"))
    {
      proc=value; 
    }
};


//Event on the board
void 
cboard_5::KeyPress(uint key, uint x, uint y,uint mask)
{

};

//Event on the board
void
cboard_5::KeyRelease(uint key, uint x, uint y,uint mask)
{
 
  
};

//Event on the board
void 
cboard_5::MouseButtonPress(uint button, uint x, uint y,uint state)
{
 
  int i;
  
  //search for the input area which owner the event    
  for(i=0;i<inputc;i++)
  {
    if(((input[i].x1 <= x)&&(input[i].x2 >= x))&&((input[i].y1 <= y)&&
       (input[i].y2 >= y)))
    {
   
      switch(input[i].id) 
      { 
        //if event is over I_ISCP area then load hex file  
        case I_ICSP:
          Window1.menu1_File_LoadHex_EvMenuActive(NULL);
          break;  
        //if event is over I_PWR area then toggle board on/off
        case I_PWR:
          if(Window1.Get_picpwr()) //if on turn off
          { 
            Window1.Set_picrun(0); 
            Window1.Set_picpwr(0); 
            avr_reset(avr);
            Reset();
            Window1.statusbar1.SetField(0,wxT("Stoped"));
          }
          else //if off turn on
          {
            Window1.Set_picpwr(1);
            Window1.Set_picrun(1);
            avr_reset(avr);          
            Reset();
            Window1.statusbar1.SetField(0,wxT("Running..."));
          } 
          break;
        //if event is over I_RST area then turn off and reset
        case I_RST:
          if(Window1.Get_picpwr())//if powered
          {
            Window1.Set_picpwr(0);
            Window1.Set_picrst(1);
          } 
          break;
      }
    }
  }
    
};

//Event on the board
void 
cboard_5::MouseButtonRelease(uint button, uint x, uint y,uint state)
{
  int i;

  //search for the input area which owner the event  
  for(i=0;i<inputc;i++)
  {
    if(((input[i].x1 <= x)&&(input[i].x2 >= x))&&((input[i].y1 <= y)&&
       (input[i].y2 >= y)))
    {
      switch(input[i].id)
      {
        //if event is over I_RST area then turn on  
        case I_RST:
          if(Window1.Get_picrst())//if powered
          {
            Window1.Set_picpwr(1);
            Window1.Set_picrst(0);

            avr_reset(avr);
            Reset();
            
          } 
          break;

      }
    } 
  }

};


//Called ever 100ms to draw board
//This is the critical code for simulator running speed
void cboard_5::Draw(CDraw *draw,double scale)
{
  int i;
  
  draw->Canvas.Init(scale,scale); //initialize draw context
  
//board  draw 
  for(i=0;i<outputc;i++) //run over all outputs
  {
    if(!output[i].r)//if output shape is a rectangle
    {
      switch(output[i].id)
      {
        case O_ON:
          draw->Canvas.SetColor (0 , 225*Window1.Get_picpwr()+30, 0 );
          break;
        case O_RX:
          draw->Canvas.SetColor (0 , pins[0].oavalue, 0 );
          break;
        case O_TX:
          draw->Canvas.SetColor (0 , pins[1].oavalue, 0 );
          break;
        case O_L:
          draw->Canvas.SetColor (0 , pins[18].oavalue, 0 );
          break;
        default:
          draw->Canvas.SetColor (0 , 0, 0 );
          break;  
      }
      
      draw->Canvas.Rectangle (1, output[i].x1, output[i].y1, 
          output[i].x2-output[i].x1,output[i].y2-output[i].y1 );
    }
  }
        


  //end draw
  draw->Canvas.End();
  draw->Update ();
  
  
  gauge1->SetValue(0.4444*(pins[4].oavalue-30)); 
  gauge2->SetValue(0.44444*(pins[10].oavalue-30)); 
  gauge3->SetValue(0.4444*(pins[11].oavalue-30)); 
  gauge4->SetValue(0.44444*(pins[14].oavalue-30));
  gauge5->SetValue(0.4444*(pins[15].oavalue-30)); 
  gauge6->SetValue(0.44444*(pins[16].oavalue-30));

}


void cboard_5::Run_CPU(void)
{
  
  int i;
  int j;
  unsigned char pi;
  const picpin *pins;
  unsigned int alm[40];
       
  int JUMPSTEPS = Window1.GetJUMPSTEPS(); //number of steps skipped
  long int NSTEPJ=Window1.GetNSTEPJ()*4.0;  //number of steps in 100ms

  
  //reset mean value
  for(pi=0;pi < MGetPinCount();pi++)
  {
    alm[pi]=0;
  };

 //read pic.pins to a local variable to speed up 
//FIXME pins = pic.pins;
  pins = MGetPinsValues();

  
 j=JUMPSTEPS+1;//step counter
 if(Window1.Get_picpwr()) //if powered
   for(i=0;i<Window1.GetNSTEP()*4;i++) //repeat for number of steps in 100ms
      {
 /*
        if(j > JUMPSTEPS)//if number of step is bigger than steps to skip 
        {  
          pic_set_pin(19,p_BT1);//Set pin 19 (RD0) with button state 
          pic_set_pin(20,p_BT2);//Set pin 20 (RD1) with switch state 
        } 
 */       
        //verify if a breakpoint is reached if not run one instruction 
        //if(!mplabxd_testbp())pic_step();
        avr_run(avr); //FIXME sleep_usec
        UpdateSerial();
        //avr->sleep_usec=0;
        if(use_oscope)Window4.SetSample();
        if(use_spare)Window5.Process();
        
        if(j > JUMPSTEPS)//if number of step is bigger than steps to skip 
        {  
          //increment mean value counter if pin is high  
          for(pi=0;pi < MGetPinCount();pi++)
          {
           alm[pi]+=pins[pi].value;
          }
        
          //set analog pin 2 (AN0) with value from scroll  
          //pic_set_apin(2,((5.0*(scroll1->GetPosition()))/
          //  (scroll1->GetRange()-1)));
          
          j=0;//reset counter
        } 
        j++;//counter increment
     }

     //calculate mean value
     for(pi=0;pi < MGetPinCount();pi++)
     { 
      cboard_5::pins[pi].oavalue= (int)(((225.0*alm[pi])/NSTEPJ)+30);
     }    
  
  
}