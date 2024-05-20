//memory saving might be required
//Commands called by ASCII

//hex=dec,cmd name, src, dest
//0x00=0 ,Ping ,check the subsystem status     ,Master,All   , {PING EPS}->{ACK AFDEVSAT EPS LIVE}or{NACK}
//0x02=2 ,ACK  ,Acknowledge reply              ,ALL   ,Master, {ACK}//not applicable
//0x03=3 ,NACK ,Not Acknowledge reply          ,ALL   ,Master, {NACK}//not applicable 
//0x04=4 ,GD   ,Get parameter data from device ,Master,All   , {GD EPS}->{EPS ACK SPC ddddddd IPC ddddddd}or{NACK}
//0x05=4 ,PD   ,Put parameter data to device   ,Master,All   , {PD EPS SPC ddddddd IPC ddddddd}->{EPS ACK PD SPC IPC}or{NACK}
//0x06=6 ,RD   ,Read data                      ,Master,All   , {RD EPS}->{EPS ACK AFDEVSAT KENYA-SPACE-AGENCY}or{NACK}
//0x07=7 ,WD   ,Write data                     ,Master,All   , {WD EPS ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss}->{EPS ACK WD}}or{NACK}
//0x0b=11,SON  ,Switch ON subsystem            ,Master,EPS   , {SON PYLD}or{SON ADCS}or{SON GCS}->{ACK}or{NACK}
//0x0c=12,SOF  ,Switch OFF subsystem           ,Master,EPS   , {SOF PYLD}or{SOF ADCS}or{SOF GCS}->{ACK}or{NACK}
//0x15=21,SM   ,Set subsystem Mode of operation,Master,ALL   , {SM ssss mmmm}->{ACK}or{NACK} ssss=subsyt, mmmm=mode
//0x16=22,GM   ,Get subsystem Mode of operation,Master,ALL   , {GM PYLD x}->{EPS ACK GM PYLD x MASTER},{GM ADCS x},{GM GCS x}
//0x17=23,GSC  ,Get Synch Counter value        ,Master,ALL   , {GSC}->{EPS ACK GSC EPS MASTER}->{}->{END}
//0x18=24,SSC  ,Set Synch Counter value        ,Master,ALL   , {SSC pppp}->{EPS ACK SSC pppp MASTER END} or {EPS NACK SSC pppp}
//0x1A=26,GFP  ,Get Function Parameter         ,Master,ALL   , {GFP EPS xxxxx}->{EPS ACK GFP MASTER yyy} or {NACK}
//0x1B=27,SFP  ,Set Function Parameter         ,Master,ALL   , {SFP EPS xxxxx yyy}->{ACK SFP xxxxx yyy} or {NACK}
//0x1C=28,FON  ,Function switch ON             ,Master,ALL   , {FON}  ->{ACK FON x}
//0x1D=29,FOF  ,Function switch OFF            ,Master,ALL   , {FOF}  ->{ACK FOF x}
//0x25=37,GOSTM,Get On line Subsystem TeleMetry,Master,ALL   , {GOSTM}->{ACK GOSTM PV1 yyyy PV2 yyyy BATV yyyy MODE y MASTER}
//0x31=49,KEN  ,Kill ENable                    ,GCS   ,EPS   , {KEN}  ->{ACK KEN} or{NACK}
//0x32=50,KDIS ,Kill DISable                   ,GCS   ,EPS   , {KDIS} ->{ACK KDIS}or{NACK}

//OK....parameter
int symbol_pause_count=1000000;
int intermission_pause_count=1000000;

//OK
int payload_status=0;
int adcs_status=0;
//int obc_status=0;
int comm_status=0;
//int eps_status=0;

//OK
int dec_spc1=symbol_pause_count//1000000;
int dec_spc2=symbol_pause_count//100000;
int dec_spc3=symbol_pause_count//10000;
int dec_spc4=symbol_pause_count//1000;
int dec_spc5=symbol_pause_count//100;
int dec_spc6=symbol_pause_count//10;
int dec_spc7=symbol_pause_count;
int dec_ipc1=intermission_pause_count//1000000;
int dec_ipc2=intermission_pause_count//100000;
int dec_ipc3=intermission_pause_count//10000;
int dec_ipc4=intermission_pause_count//1000;
int dec_ipc5=intermission_pause_count//100;
int dec_ipc6=intermission_pause_count//10;
int dec_ipc7=intermission_pause_count;

//OK
int zero=48; int one  =49; int two=50  ; int three=51; int four=52; int five=53;
int six =54; int seven=55; int eight=56; int nine=57;
int A=65;int B=66;int C=67;int D=68;int E=69;int F=70;int G=71;int H=72;int I=73;int J=74;
int K=75;int L=76;int M=77;int N=78;int O=79;int P=80;int Q=81;int R=82;int S=83;int T=84;
int U=85;int V=86;int W=87;int X=88;int Y=89;int Z=90;int space=32;int hyphen=45;

//OK.....data
int eps_data[100]={A,F,D,E,V,S,A,T,space,K,E,N,Y,A,hyphen,S,P,A,C,E,hyphen,A,G,E,N,C,Y,space,E,P,S};


//OK
int ascii_to_dec(int x){
if(==zero ){return 0;}//if
if(==one  ){return 1;}//if
if(==two  ){return 2;}//if
if(==three){return 3;}//if
if(==four ){return 4;}//if
if(==five ){return 5;}//if
if(==six  ){return 6;}//if
if(==seven){return 7;}//if
if(==eight){return 8;}//if
if(==nine ){return 9;}//if
}//ascii_to_dec

//OK
int receive_binary [400];
int receive_symbol [50 ];//50byte
int transmit_binary[400];
int transmit_symbol[50 ];//50byte

//OK
//initialize
for(int index=0;index<=399;index++){receive_binary [index]=0;}
for(int index=0;index<=49 ;index++){receive_symbol [index]=0;}
for(int index=0;index<=399;index++){transmit_binary[index]=0;}
for(int index=0;index<=49 ;index++){transmit_symbol[index]=0;}

//OK
int bit_transmit(int value){//bit_transmit
if(value){
  /*review TX VALUE 1*/;
  //for(int x=0;x<255;x++){for(int x=0;x<255;x++){for(int x=0;x<255;x++){}}}
  for(int i=0;i<=symbol_pause_count;i++){}//for.... possible unsupported count value
}//if 1
if(!value){
  /*review TX VALUE 0*/;
  for(int i=0;i<=symbol_pause_count;i++){};
}//if 0
/*review TX VALUE INTERMISSION*/;
for(int i=0;i<=intermission_pause_count;i++){};//for intermission
return 0;
}//bit_transmit

//OK
int byte_transmit(int mybytenumber){
for(int leftshift=7;leftshift>=0;leftshift--){
bit_transmit( (int) (mybytenumber&(1<<leftshift)) );
}//for
return 0;
}//byte_transmit

//OK
int receive_binary_to_receive_symbol(){
for(int symbol_index=0;symbol_index<=49;symbol_index++){
  int sum=0;
  for(int leftshift=7;leftshift>=0;leftshift--){sum=sum+(receive_binary[(symbol*8)+(7-leftshift)]*((int)(1<<leftshift)));}//for
  receive_symbol[symbol_index]=sum;
}//for
return 0;
}//receive_binary_to_receive_symbol


//OK
int ack_response(){
if(/*review TX ACTIVE*/){
int response_array[]={A,C,K};
for(int index=0;index<=2;index++){//for
  byte_transmit(response_array[index]);
}//for
}//if
return 0;
}//ack_repsonse

//OK
int nack_response(){
if(/*review TX ACTIVE*/){//if
 int response_array[]={N,A,C,K};
 for(int index=0;index<=3;index++){//for
   byte_transmit(response_array[index]);
 }//for
}//if
return 0;
}//nack_response


//OK
int ping_check(){//ping response
if(
(receive_symbol[0]==P    )&&(receive_symbol[1]==I)&&(receive_symbol[2]==N)&&(receive_symbol[3]==G)&&
(receive_symbol[4]==space)&&(receive_symbol[5]==E)&&(receive_symbol[6]==P)&&(receive_symbol[7]==S)&&
/*review TX ACTIVE*/
){//ping detected
int response_array[]={A,C,K,space,A,F,D,E,V,S,A,T,space,E,P,S,space,L,I,V,E};
for(int index=0;index<=20;index++){//for
  byte_transmit((response_array[index]));
}//for
}//ping detected
else{nack_response();}
return 0;
}//ping check


//OK
int gd_check(){
if(
(receive_symbol[0]==G)&&(receive_symbol[1]==D)&&(receive_symbol[2]==space)&&
(receive_symbol[3]==E)&&(receive_symbol[4]==P)&&(receive_symbol[5]==S)&&
/*review TX ACTIVE*/
){//gd detected
int response_array[]={A,C,K,space,
                      S,P,C,space,
                      dec_spc1,dec_spc2,dec_spc3,dec_spc4,dec_spc5,dec_spc6,dec_spc7,space,
                      I,P,C,space,
                      dec_ipc1,dec_ipc2,dec_ipc3,dec_ipc4,dec_ipc5,dec_ipc6,dec_ipc7};
for(int index=0;index<=26;index++){//for
  byte_transmit((response_array[index]));
}//for
}//gd detected
else{nack_response();}
return 0;
}


//OK
//{PD EPS SPC ddddddd IPC ddddddd}->{EPS ACK PD SPC IPC}or{NACK}
int pd_check(){
if(
(receive_symbol[0 ]==P)&&(receive_symbol[1 ]==D)&&(receive_symbol[2 ]==space)&&
(receive_symbol[3 ]==E)&&(receive_symbol[4 ]==P)&&(receive_symbol[5 ]==S)&&(receive_symbol[6 ]==space)&&
(receive_symbol[7 ]==S)&&(receive_symbol[8 ]==P)&&(receive_symbol[9 ]==C)&&(receive_symbol[10]==space)&&
(receive_symbol[19]==I)&&(receive_symbol[20]==P)&&(receive_symbol[21]==C)&&(receive_symbol[22]==space)&&
/*review TX ACTIVE*/
){//pd detected
symbol_pause_count=((ascii_to_dec(receive_symbol[11])*1000000)+
                    (ascii_to_dec(receive_symbol[12])*100000 )+
                    (ascii_to_dec(receive_symbol[13])*10000  )+
                    (ascii_to_dec(receive_symbol[14])*1000   )+
                    (ascii_to_dec(receive_symbol[15])*100    )+
                    (ascii_to_dec(receive_symbol[16])*10     )+
                     ascii_to_dec(receive_symbol[17])        );
intermission_pause_count=((ascii_to_dec(receive_symbol[23])*1000000)+
                          (ascii_to_dec(receive_symbol[24])*100000 )+
                          (ascii_to_dec(receive_symbol[25])*10000  )+
                          (ascii_to_dec(receive_symbol[26])*1000   )+
                          (ascii_to_dec(receive_symbol[27])*100    )+
                          (ascii_to_dec(receive_symbol[28])*10     )+
                           ascii_to_dec(receive_symbol[29])        );
int response_array[31]={E,P,S,space,
                        A,C,K,space,
                        P,D,space,
                        S,P,C,space,
                        I,P,C};
for(int symbol_index=0;symbol_index<=17;symbol_index++){//for
  byte_transmit((response_array[symbol_index]));
}//for
}//pd detected
else{nack_response();}
return 0;
}//pd_check


//OK
//{RD EPS}->{EPS ACK AFDEVSAT KENYA-SPACE-AGENCY}or{NACK}
//int eps_data[100]={E,P,S,space,ACK,space,A,F,D,E,V,S,A,T,space,K,E,N,Y,A,hyphen,SPACE,hyphen,AGENCY}, default after powering up
int rd_check(){
if(
(receive_symbol[0 ]==R)&&(receive_symbol[1 ]==D)&&(receive_symbol[2 ]==space)&&
(receive_symbol[3 ]==E)&&(receive_symbol[4 ]==P)&&(receive_symbol[5 ]==S)
){//rd detected
for(int index=0;index<=99;index++){
  byte_transmit((eps_data[index]));
}//for..transmit entire 100 byte array
}//rd_detected
else{nack_response();}
return 0;
}//rd_check


//OK
//{WD EPS ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss}->{EPS ACK WD}}or{NACK}
int wd_check(){
if(
(receive_symbol[0 ]==W)&&(receive_symbol[1 ]==D)&&(receive_symbol[2 ]==space)&&
(receive_symbol[3 ]==E)&&(receive_symbol[4 ]==P)&&(receive_symbol[5 ]==S)
){//rd detected
for(int index=7;index<=106;index++){
  eps_data[index-7]=receive_symbol[index];
}//for...overwrite the data memory
int response={E,P,S,space,A,C,K,space,W,D};
for(int index=0;index<=9;index++){
  byte_transmit(response[index]);
}//for
}//rd_detected
else{nack_response();}
return 0;
}//wd_check

//OK
//{SON PYLD}or{SON ADCS}or{SON GCS}->{ACK}or{NACK}
int son_check(){
if(
(receive_symbol[0 ]==S)&&(receive_symbol[1 ]==O)&&(receive_symbol[2 ]==N)&&(receive_symbol[3 ]==space)
){//son detected
  if((receive_symbol[4 ]==P)&&(receive_symbol[5 ]==Y)&&(receive_symbol[6 ]==L)&&(receive_symbol[7 ]==D)){
  /*review payload ON*/
  ack_response();
  }//if son pyld
  if((receive_symbol[4 ]==A)&&(receive_symbol[5 ]==D)&&(receive_symbol[6 ]==C)&&(receive_symbol[7 ]==S)){
  /*review adcs ON*/
  ack_response();
  }//if son adcs
  if((receive_symbol[4 ]==G)&&(receive_symbol[5 ]==C)&&(receive_symbol[6 ]==S)){
  /*review gcs ON*/
  ack_response();
  }//if son gcs
}//son_detected
else{nack_response();}
return 0;
}//son_check

//OK
//{SOF PYLD}or{SOF ADCS}or{SOF GCS}->{ACK}or{NACK}
int sof_check(){
if(
(receive_symbol[0 ]==S)&&(receive_symbol[1 ]==O)&&(receive_symbol[2 ]==F)&&(receive_symbol[3 ]==space)
){//son detected
  if((receive_symbol[4 ]==P)&&(receive_symbol[5 ]==Y)&&(receive_symbol[6 ]==L)&&(receive_symbol[7 ]==D)){
  /*review payload OFF*/
  ack_response();
  }//if son pyld
  if((receive_symbol[4 ]==A)&&(receive_symbol[5 ]==D)&&(receive_symbol[6 ]==C)&&(receive_symbol[7 ]==S)){
  /*review adcs OFF*/
  ack_response();
  }//if son adcs
  if((receive_symbol[4 ]==G)&&(receive_symbol[5 ]==C)&&(receive_symbol[6 ]==S)){
  /*review gcs OFF*/
  ack_response();
  }//if son gcs
}//son_detected
else{nack_response();}
return 0;
}//sof_check


//OK
//{SM ssss mmmm}->{ACK}or{NACK} ssss=subsyt, mmmm=mode
//Command   Subsystem    Modes             V    A
//--------------------------------------------------
//SM CCU ACTIVESTANDBY 3V3  0A05
//SM CCU ACTIVEBEACON  3V3  1A5
//SM CCU UHFCOMM       3V3  2A
//--------------------------------------------------
//SM DEPLOYFUSE ACTIVE6S  5V0  1A
//-------------------------------------------------- 
//SM OBC ACTIVESTANDBY 3V3  0A1
//SM OBC ACTIVEBEACON  3V3  1A5
//SM OBC UHFCOMM       3V3  2A0
//-----------------------------------------
//SM ADCS DETUMBLE          
//SM ADCS STANDBY                     
//SM ADCS IMAGINGNADIR            
//SM ADCS DOWNLOAD                  
//-----------------------------------------
//SM GPS ACTIVE          5V0  0A6
//-----------------------------------------
//SM PAYLOAD ACTIVE3CAMERA  5V0  0A94
//SM PAYLOAD ACTIVEPL       5V0  0A6
//SM PAYLOAD ACTIVECH       5V0  0A6
//SM PAYLOAD XBAND          12V0 0A92
//-----------------------------------------
int sm_check(){
int sm=(int)((receive_symbol[0]==S)&&(receive_symbol[1]==M));
int sm_ccu_active=(int)(
                  sm&&(receive_symbol[2]==space)&&
                  (receive_symbol[3]==C)&&(receive_symbol[4]==C)&&(receive_symbol[5]==U)&&(receive_symbol[6]==space)&&
                  (receive_symbol[7]==A)&&(receive_symbol[8]==C)&&(receive_symbol[9]==T)&&(receive_symbol[10]==I)&&(receive_symbol[11]==V)&&(receive_symbol[12]==E)
                  );
int ssm_ccu_activestandby=(int)(
                  sm_ccu_active&&
                  (receive_symbol[13]==S)&&(receive_symbol[14]==T)&&(receive_symbol[15]==A)&&(receive_symbol[16]==N)&&(receive_symbol[17]==D)&&
                  (receive_symbol[18]==B)&&(receive_symbol[19]==Y)
                  );
int sm_ccu_activebeacon=(int)(
                  sm_ccu_active&&
                  (receive_symbol[13]==B)&&(receive_symbol[14]==E)&&(receive_symbol[15]==A)&&(receive_symbol[16]==C)&&(receive_symbol[17]==O)&&(receive_symbol[18]==N)
                  );
int sm_ccu_uhfcomm=(int)(
                  sm&&(receive_symbol[2]==space)&&(receive_symbol[3]==C)&&(receive_symbol[4]==C)&&(receive_symbol[5]==U)&&
                  (receive_symbol[6]==U)&&(receive_symbol[7]==H)&&(receive_symbol[8]==F)&&
                  (receive_symbol[9]==C)&&(receive_symbol[10]==O)&&(receive_symbol[11]==M)&&(receive_symbol[12]==M)
                  );
int sm_deployfuse_active6s=(int)(
                  sm&&(receive_symbol[2]==space)&&
                  (receive_symbol[3 ]==D )&&(receive_symbol[4 ]==E)&&(receive_symbol[5 ]==P)&&(receive_symbol[6 ]==L)&&(receive_symbol[7 ]==O)&&(receive_symbol[8 ]==Y)&&
                  (receive_symbol[9 ]==F )&&(receive_symbol[10]==U)&&(receive_symbol[11]==S)&&(receive_symbol[12]==E)&&(receive_symbol[13]==space)&&
                  (receive_symbol[14]==A )&&(receive_symbol[15]==C)&&(receive_symbol[16]==T)&&(receive_symbol[17]==I)&&(receive_symbol[18]==V)&&(receive_symbol[19]==E)&&
                  (receive_symbol[20]=six)&&(receive_symbol[21]==S)
                  );
int sm_obc_active=(int)(
                  sm&&(receive_symbol[2]==space)&&
                  (receive_symbol[3]==O)&&(receive_symbol[4]==B)&&(receive_symbol[5]==C)&&(receive_symbol[6]==space)&&
                  (receive_symbol[7]==A)&&(receive_symbol[8]==C)&&(receive_symbol[9]==T)&&(receive_symbol[10]==I)&&(receive_symbol[11]==V)&&(receive_symbol[12]==E)
                  );
int sm_obc_activestandby=(int)(
                  sm_obc_active&&
                  (receive_symbol[13]==S)&&(receive_symbol[14]==T)&&(receive_symbol[15]==A)&&(receive_symbol[16]==N)&&(receive_symbol[17]==D)&&
                  (receive_symbol[18]==B)&&(receive_symbol[19]==Y)
                  );
int sm_obc_activebeacon=(int)(
                  sm_obc_active&&
                  (receive_symbol[13]==B)&&(receive_symbol[14]==E)&&(receive_symbol[15]==A)&&(receive_symbol[16]==C)&&(receive_symbol[17]==O)&&(receive_symbol[18]==N)
                  );
int sm_obc_uhfcomm=(int)(
                  sm&&(receive_symbol[2]==space)&&
                  (receive_symbol[3]==O)&&(receive_symbol[4]==B)&&(receive_symbol[5]==C)&&(receive_symbol[6]==space)&&
                  (receive_symbol[7]==U)&&(receive_symbol[8]==H)&&(receive_symbol[9]==F)&&(receive_symbol[10]==C)&&(receive_symbol[11]==O)&&(receive_symbol[12]==M)&&(receive_symbol[13]==M)
                  );
int sm_adcs       =(int)(
                  sm&&(receive_symbol[2]==space)&&(receive_symbol[3]==A)&&(receive_symbol[4]==D)&&(receive_symbol[5]==C)&&(receive_symbol[6]==S)
                  );
int sm_adcs_detumble=(int)(
                  sm_adcs&&(receive_symbol[7]==space)&&
                  (receive_symbol[8]==D)&&(receive_symbol[9]==E)&&
                  (receive_symbol[10]==T)&&(receive_symbol[11]==U)&&(receive_symbol[12]==M)&&(receive_symbol[13]==B)&&(receive_symbol[14]==L)&&(receive_symbol[15]==E)
                  );
int sm_adcs_standby=(int)(
                  sm_adcs&&(receive_symbol[7]==space)&&
                  (receive_symbol[8]==S)&&(receive_symbol[9]==T)&&(receive_symbol[10]==A)&&(receive_symbol[11]==N)&&(receive_symbol[12]==D)&&
                  (receive_symbol[13]==B)&&(receive_symbol[14]==Y)
                  );
int sm_adcs_imagingnadir=(int)(
                  sm_adcs&&(receive_symbol[7]==space)&&
                  (receive_symbol[8]==I)&&(receive_symbol[9]==M)&&(receive_symbol[10]==A)&&(receive_symbol[11]==G)&&(receive_symbol[12]==I)&&
                  (receive_symbol[13]==N)&&(receive_symbol[14]==G)&&(receive_symbol[15]==N)&&(receive_symbol[16]==A)&&(receive_symbol[17]==D)&&
                  (receive_symbol[18]==I)&&(receive_symbol[19]==R)
                  );
int sm_adcs_download=(int)(
                  sm_adcs&&(receive_symbol[7]==space)&&
                  (receive_symbol[8]==D)&&(receive_symbol[9]==O)&&(receive_symbol[10]==W)&&(receive_symbol[11]==N)&&
                  (receive_symbol[12]==L)&&(receive_symbol[13]==O)&&(receive_symbol[14]==A)&&(receive_symbol[15]==D)
                  );
int sm_gps_active=(int)(
                  sm&&(receive_symbol[2]==space)&&
                  (receive_symbol[3]==G)&&(receive_symbol[4]==P)&&(receive_symbol[5]==S)&&(receive_symbol[6]==space)&&
                  (receive_symbol[7]==A)&&(receive_symbol[8]==C)&&(receive_symbol[9]==T)&&(receive_symbol[10]==I)&&
                  (receive_symbol[11]==V)&&(receive_symbol[12]==E)
                  );
int sm_payload=(int)(
                  sm&&(receive_symbol[2]==space)&&
                  (receive_symbol[3]==P)&&(receive_symbol[4]==A)&&(receive_symbol[5]==Y)&&
                  (receive_symbol[6]==L)&&(receive_symbol[7]==O)&&(receive_symbol[8]==A)&&(receive_symbol[9]==D)
                  );
int sm_payload_active3camera=(int)(
                  sm_payload&&(receive_symbol[10]==space)&&
                  (receive_symbol[11]==A)&&(receive_symbol[12]==C)&&(receive_symbol[13]==T)&&(receive_symbol[14]==I)&&(receive_symbol[15]==V)&&(receive_symbol[16]==E)&&
                  (receive_symbol[17]==three)&&(receive_symbol[18]==C)&&(receive_symbol[19]==A)&&(receive_symbol[20]==M)&&
                  (receive_symbol[21]==E)&&(receive_symbol[22]==R)&&(receive_symbol[23]==A)
                  );
int sm_payload_activepl=(int)(
                  sm_payload&&(receive_symbol[10]==space)&&
                  (receive_symbol[11]==A)&&(receive_symbol[12]==C)&&(receive_symbol[13]==T)&&(receive_symbol[14]==I)&&(receive_symbol[15]==V)&&(receive_symbol[16]==E)&&
                  (receive_symbol[17]==P)&&(receive_symbol[18]==L)
                  );
int sm_payload_activeph=(int)(
                  sm_payload&&(receive_symbol[10]==space)&&
                  (receive_symbol[11]==A)&&(receive_symbol[12]==C)&&(receive_symbol[13]==T)&&(receive_symbol[14]==I)&&(receive_symbol[15]==V)&&(receive_symbol[16]==E)&&
                  (receive_symbol[17]==P)&&(receive_symbol[18]==H)
                  );
int sm_payload_xband=(int)(
                  sm_payload&&(receive_symbol[10]==space)&&
                  (receive_symbol[11]==X)&&(receive_symbol[12]==B)&&(receive_symbol[13]==A)&&(receive_symbol[14]==N)&&(receive_symbol[15]==D)
                  );
if(
sm_ccu_activestandby     || sm_ccu_activebeacon  || sm_ccu_uhfcomm      || sm_deployfuse_active6s ||
sm_obc_activestandby     || sm_obc_activebeacon  || sm_obc_uhfcomm      || sm_adcs_detumble       ||
sm_adcs_standby          || sm_adcs_imagingnadir || sm_adcs_download    || sm_gps_active          || 
sm_payload_active3camera || sm_payload_activepl  || sm_payload_activeph || sm_payload_xband
){//if
if(sm_ccu_activestandby    ){/*review*/;ack_response();}//if
if(sm_ccu_activebeacon     ){/*review*/;ack_response();}//if
if(sm_ccu_uhfcomm          ){/*review*/;ack_response();}//if
if(sm_deployfuse_active6s  ){/*review*/;ack_response();}//if
if(sm_obc_activestandby    ){/*review*/;ack_response();}//if
if(sm_obc_activebeacon     ){/*review*/;ack_response();}//if
if(sm_obc_uhfcomm          ){/*review*/;ack_response();}//if
if(sm_adcs_standby         ){/*review*/;ack_response();}//if
if(sm_adcs_imagingnadir    ){/*review*/;ack_response();}//if
if(sm_adcs_download        ){/*review*/;ack_response();}//if
if(sm_gps_active           ){/*review*/;ack_response();}//if
if(sm_payload_active3camera){/*review*/;ack_response();}//if
if(sm_payload_activepl     ){/*review*/;ack_response();}//if
if(sm_payload_activeph     ){/*review*/;ack_response();}//if
if(sm_payload_xband        ){/*review*/;ack_response();}//if
}//if
else{nack_response();}
return 0;
}//sm_check


//GM CCU        -> 
//GM DEPLOYFUSE ->
//GM OBC        ->
//GM ADCS       ->
//GM GPS        ->
//GM PAYLOAD    ->
int gm_check(){
int gm=(int)(gm&&(receive_symbol[0]==G)&&(receive_symbol[1]==M));
int gm_ccu=(int)(gm&&(receive_symbol[2]==space)&&(receive_symbol[3]==C)&&(receive_symbol[4]==C)&&(receive_symbol[5]==U));
int gm_deployfuse=(int)(
       gm&&(receive_symbol[2]==space)&&
       (receive_symbol[3]==D)&&(receive_symbol[4]==E)&&(receive_symbol[5]==P)&&(receive_symbol[6]==L)&&(receive_symbol[7]==O)&&(receive_symbol[8]==Y)&&
       (receive_symbol[9]==F)&&(receive_symbol[10]==U)&&(receive_symbol[11]==S)&&(receive_symbol[12]==E));
int gm_obc=(int)(gm&&(receive_symbol[2]==space)&&(receive_symbol[3]==O)&&(receive_symbol[4]==B)&&(receive_symbol[5]==C));
int gm_adcs=(int)(gm&&(receive_symbol[2]==space)&&(receive_symbol[3]==A)&&(receive_symbol[4]==D)&&(receive_symbol[5]==C)&&(receive_symbol[6]==S));
int gm_gps=(int)(gm&&(receive_symbol[2]==space)&&(receive_symbol[3]==G)&&(receive_symbol[4]==P)&&(receive_symbol[5]==S));
int gm_payload=(int)(
       gm&&(receive_symbol[2]==space)&&
       (receive_symbol[3]==P)&&(receive_symbol[4]==A)&&(receive_symbol[5]==Y)&&(receive_symbol[6]==L)&&(receive_symbol[7]==O)&&(receive_symbol[8]==A)&&(receive_symbol[9]==D));
/*review*/
int mode=(int)(mode&&(receive_symbol[0]==M)&&(receive)_symbol[1]==O)&&(receive_symbol[2]==D)&&(receive_symbol[3]==E));
int mode_ccu_activestandby=(int)(mode&&(receive_symbol[4]==space)&&(receive)_symbol[5]==C)&&(receive_symbol[6]==C)&&(receive_symbol[7]==U)&&(receive_symbol[8]=space)&&(receive_symbol[9]==A)&&(receive_symbol[10]==C)&&(receive_symbol[11]==T)&&(receive_symbol[12]==I)&&(receive_symbol[;
int mode_ccu_activebeacon;
int mode_ccu_uhfcomm;
int mode_deployfuse_active6s;
int mode_obc_activestandby;
int mode_obc_activebeacon;
int mode_obc_uhfcomm;
int mode_adcs_standby;
int mode_adcs_imagingnadir;
int mode_adcs_download;
int mode_gps_active;
int mode_payload_active3camera;
int mode_payload_activepl;
int mode_payload_activeph;
int mode_payload_xband;
if(gm_ccu)|| gm_deployfuse || gm_obc || gm_adcs || gm_gps || gm_payload ){
ack_response();byte_transmit(space);
if(gm_ccu       ){
  if(mode_ccu_activestandby){
    int response[]={M,O,D,E,space,C,C,U,space,A,C,T,I,V,E,S,T,A,N,D,B,Y};for(int index=0;index<=21;index++){byte_transmit(response[index]);}
  }
  if(mode_ccu_activebeacon ){
    int response[]={M,O,D,E,space,C,C,U,space,A,C,T,I,V,E,B,E,A,C,O,N};for(int index=0;index<=20;index++){byte_transmit(response[index]);}
  }
  if(mode_ccu_uhfcomm      ){
    int response[]={C,C,U,space,U,H,F,C,O,M,M};for(int index=0;index<=10;index++){byte_transmit(response[index]);}
  }
}//if
if(gm_deployfuse){
  if(mode_deployfuse_active6s){
    int response[]={F,U,S,E,space,D,E,P,L,O,Y,E,D};for(int index=0;index<=12;index++){byte_transmit(response[index]);}
  }
}//if
if(gm_obc       ){
  if(mode_obc_activestandby){
    int response[]={M,O,D,E,space,O,B,C,space,A,C,T,I,V,E,S,T,A,N,D,B,Y};for(int index=0;index<=21;index++){byte_transmit(response[index]);}
  }
  if(mode_obc_activebeacon ){
    int response[]={M,O,D,E,space,O,B,C,space,A,C,T,I,V,E,B,E,A,C,O,N};for(int index=0;index<=20;index++){byte_transmit(response[index]);}
  }
  if(mode_obc_uhfcomm      ){
    int response[]={M,O,D,E,space,O,B,C,U,H,F,C,O,M,M};for(int index=0;index<=15;index++){byte_transmit(response[index]);}
  }
}//if
if(gm_adcs      ){
  if(mode_adcs_standby     ){
    int response[]={A,D,C,S,space,S,T,A,N,D,B,Y};for(int index=0;index<=11;index++){byte_transmit(response[index]);}
  }
  if(mode_adcs_imagingnadir){
    int response[]={A,D,C,S,space,I,M,A,G,I,N,G,N,A,D,I,R};for(int index=0;index<=16;index++){byte_transmit(response[index]);}
  }
  if(mode_adcs_download    ){
    int response[]={A,D,C,S,space,D,O,W,N,L,O,A,D};for(int index=0;index<=12;index++){byte_transmit(response[index]);}
  }
}//if
if(gm_gps       ){
  if(mode_gps_active       ){
     int response[]={G,P,S,space,A,C,T,I,V,E};for(int index=0;index<=9;index++){byte_transmit(response[index]);}
  }
}//if
if(gm_payload   ){
  if(mode_payload_active3camera){
    int response[]={P,A,Y,L,O,A,D,space,A,C,T,I,V,E,3,C,A,M,E,R,A};for(int index=0;index<=20;index++){byte_transmit(response[index]);}
  }
  if(mode_payload_activepl     ){
    int response[]={P,A,Y,L,O,A,D,space,A,C,T,I,V,E,P,L};for(int index=0;index<=15;index++){byte_transmit(response[index]);}
  }
  if(mode_payload_activeph     ){
    int response[]={P,A,Y,L,O,A,D,space,A,C,T,I,V,E,P,H};for(int index=0;index<=15;index++){byte_transmit(response[index]);}
  }
  if(mode_payload_xband        ){
    int response[]={P,A,Y,L,O,A,D,space,X,B,A,N,D};for(int index=0;index<=12;index++){byte_transmit(response[index]);}
  }
}//if
}//if
else{nack_response();}
return 0;
}//gm_check


//{GSC}->{EPS ACK GSC EPS MASTER}->{}->{END}
int gsc_check(){
return 0;
}//gsc_check

int ssc_check(){
return 0;
}//ssc_check

int gfp_check(){
return 0;
}//gfp_check

int sfp_check(){
return 0;
}//sfp_check

int fon_check(){
return 0;
}//fon_check

int fof_check(){
return 0;
}//fof_check

int gostm_check(){
return 0;
}//

int ken_check(){
if(
(receive_symbol[0]==K)&&(receive_symbol[1]==E)&&(receive_symbol[2]==N)&&(receive_symbol[3]==S)&&/*review TX ACTIVE*/
){//kdis detected
/*review KDIS*/
int response_array[12]={E,P,S,space,A,C,K,space,K,D,I,S};
for(int symbol_index=0;symbol_index<=11;symbol_index++){//for
  byte_transmit((response_array[symbol_index]));
}//for
}//kdis detected
else{if(/*review TX ACTIVE*/){nack_response();}}
return 0;
}


int kdis_check(){
if(
(receive_symbol[0]==K)&&(receive_symbol[1]==D)&&(receive_symbol[2]==I)&&(receive_symbol[3]==S)&&/*review TX ACTIVE*/
){//kdis detected
/*review KDIS*/
int response_array[12]={E,P,S,space,A,C,K,space,K,D,I,S};
for(int symbol_index=0;symbol_index<=11;symbol_index++){//for
byte_transmit((response_array[symbol_index]));
}//for
}//kdis detected
else{if(/*review TX ACTIVE*/){nack_response();}}
return 0;
}






/*******************************************/
int payload_status=0;
int adcs_status=0;
int obc_status=0;
int comm_status=0;
int eps_status=0;

int statusframebitnumber=0;

int transmit_bit_position=0;


int executeframe(){
//action
if((receive_symbol[0]==F )&&(receive_symbol[1]==O)&&(receive_symbol[2]==N )&&(receive_symbol[3]== )){
//action&change status
}
if((receive_symbol[0]== )&&(receive_symbol[1]== )&&(receive_symbol[2]== )&&(receive_symbol[3]== )){
//action&change status
}
if((receive_symbol[0]== )&&(receive_symbol[1]== )&&(receive_symbol[2]== )&&(receive_symbol[3]== )){
//action&change status
}
return 0;
}//executeframe


int shiftleftstore(int value){
for(int index=0;index<=158;index++){receive[index]=receive[index+1];};
receive[159]=value;
return 0;
}//shiftleftstore

int main(){///main
while(1){//while
//receive raw binary
int skip=0;
if(skip==0,RXA()==, RXB()==, RXC()==){shiftleftstore(0);executeframe();while(RXA()==, RXB()==, RXC()==);skip=1;}
if(skip==0,RXA()==, RXB()==, RXC()==){shiftleftstore(1);executeframe();while(RXA()==, RXB()==, RXC()==);skip=1;}
if(skip==0,RXA()==, RXB()==, RXC()==){                                 while(RXA()==, RXB()==, RXC()==);skip=1;}/*intermission*/
}//while
}//main

