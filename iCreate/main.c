#include <kipr/wombat.h>

int main() {
    create_connect();
    create_start();
    enable_servo(3);
    set_servo_position(3, 400);
    create_drive_direct(250, -250);
    msleep(450);
    create_drive_direct(250, 250);
    msleep(800);
    create_drive_direct(500, -500);
    msleep(500);
    create_drive_direct(-500, 500);
    msleep(500);
    create_drive_direct(-250, -250);
    msleep(1300);
    set_servo_position(3, 2200);
    create_drive_direct(250, 250);
    msleep(4000);
    create_drive_direct(250, -250);
    msleep(750);
    create_drive_direct(-250, -250);
    msleep(1800);
    create_drive_direct(250, 250);
    msleep(4800);
    create_drive_direct(-250, 250);
    msleep(1400);

    return 0;
}
