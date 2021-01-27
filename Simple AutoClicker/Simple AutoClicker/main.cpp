#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>

static int left_cps = 12;
POINT pos{ 0, 0 };

void mouse_up( ) {
    std::this_thread::sleep_for( std::chrono::milliseconds( ( 1000 / left_cps ) / 2 ) );

    SendMessageA (
        FindWindowA( "LWJGL", nullptr ),
        WM_LBUTTONUP,
        MK_LBUTTON,
        MAKELPARAM( pos.x, pos.y )
    );
}

void mouse_down( ) {
    std::this_thread::sleep_for( std::chrono::milliseconds( ( 1000 / left_cps ) / 2 ) );

    SendMessageA (
        FindWindowA( "LWJGL", nullptr ),
        WM_LBUTTONDOWN,
        MK_LBUTTON,
        MAKELPARAM( pos.x, pos.y )
    );

    mouse_up( );
}

int main( ) {
    while ( true ) {
        if ( GetAsyncKeyState( VK_LBUTTON ) & 0x8000 ) {
            mouse_down( );
        }
    }
}