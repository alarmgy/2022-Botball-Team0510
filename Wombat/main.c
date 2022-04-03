#include <kipr/wombat.h>
#include "drive.h"

#define ARM_LIFTED 800
#define TOP_HAT_THRESHOLD 3200
#define left 500
#define right 500
#define bleft -500
#define bright -500

int main(){
    wait_for_light(0);
    shut_down_in(117);
    
    enable_servos();
    set_servo_position(0, 400);//start
    set_servo_position(2, 0);
    msleep(3000);
    mav(0, left);
    mav(1, right);
    msleep(5000);
    mav(1, bright);//turning
    msleep(2250);
    mav(0, bleft);
    msleep(3000);
    mav(0, 990);//!!
    mav(1, 990);
    while (digital(9)!=1){//waiting for button sensor
        msleep(20);
    }
    mav(0,0);
    mav(1,0);
    msleep(100);
    set_servo_position(0, 0); //grabbing the transporter
    msleep(1000);
    set_servo_position(2, 1500);
    msleep(1000);
    set_servo_position(0, 400);
    msleep(1000);
    mav(0, bleft);//driving backwards and lowering the arm
    mav(1, bright);
    msleep(4500);
    set_servo_position(0, 0);
    // while (analog(0)<TOP_HAT_THRESHOLD){
    mav(0, -500);//driving backward until it touches the back!!
    mav(1, -500);
    msleep(30000);
    // }
    mav(0, left);//moving the transporter into the starting box
    mav(1, -right);
    msleep(3000);
    set_servo_position(0, 400);//letting go of the transporter
    set_servo_position(2, 400);
    mav(0, bleft);//moving to its final position
    mav(1, bright);
    msleep(2000);
    disable_servos();
    
    return 0;
}

