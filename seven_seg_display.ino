const int segmentPins[] = {2,3,4,5,6,7,8,9};


void displayNumber(int num){
    byte patterns[] = {
        B11000000, //0
        B11111001, //1
        B00100100,//2
        B00110000, //3
        B00011001, //4
        B00010010, //5
        B00000010, //6
        B11111000, //7
        B00000000, //8
        B00010000, //9
    };
    for(int i=0;i<8;i++){
        digitalWrite(segmentPins[i],bitRead(patterns[num],i));
    }
}
void displayNumber2(int num){
        byte patterns[] = {
        B00000000, //8
        B11111000, //7
        B00000010, //6
        B00010010, //5
        B00011001, //4
        B00110000, //3
        B00100100,//2
        B11111001
        };        
    for(int i=0;i<8;i++){
        digitalWrite(segmentPins[i],bitRead(patterns[num],i));
    }
}

void setup(){
    for(int i=0;i<8;i++){
        pinMode(segmentPins[i],OUTPUT);
    }
}

void loop(){
    for (int num =0;num < 10; num++){
        displayNumber(num);
        delay(1000);
    }
    for(int num = 0; num<8;num++){
        displayNumber2(num);
        delay(1000);
    }
}
