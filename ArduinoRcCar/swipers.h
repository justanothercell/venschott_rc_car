namespace swipers {
    const int SWIPER_SERVO = 3;

    Servo swiper;

    void setup(){
        pinMode(SWIPER_SERVO, OUTPUT);
        swiper.attach(SWIPER_SERVO);
    }

    void loop(){

    }
}