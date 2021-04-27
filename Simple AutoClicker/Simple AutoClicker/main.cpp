#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>

static int left_cps = 12;
static POINT pos{ 0, 0 };

auto mouse_up( ) -> void {
    std::this_thread::sleep_for( std::chrono::milliseconds( ( 1000 / left_cps ) / 2 ) );

    SendMessageA (
        FindWindowA( "LWJGL", nullptr ),
        WM_LBUTTONUP,
        MK_LBUTTON,
        MAKELPARAM( pos.x, pos.y )
    );
}

auto mouse_down( ) -> void {
    std::this_thread::sleep_for( std::chrono::milliseconds( ( 1000 / left_cps ) / 2 ) );

    SendMessageA (
        FindWindowA( "LWJGL", nullptr ),
        WM_LBUTTONDOWN,
        MK_LBUTTON,
        MAKELPARAM( pos.x, pos.y )
    );

    mouse_up( );
}

auto main( ) -> int {
    while ( true ) {
        if ( GetAsyncKeyState( VK_LBUTTON ) & 0x8000 ) {
            mouse_down( );
        }
        else {
            std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
        }
    }
}
