
#include "camera.h"
#include "game.h"
#include "xtypes.h"
#include "resources.h"

Vect2D_s16 cameraPosition;
AABB cameraDeadzone;

void setupCamera(Vect2D_u16 deadZoneCenter, u16 deadZoneWidth, u16 deadZoneHeight) {
	//Calculates the bounds of the deadZone
	cameraDeadzone.min.x = deadZoneCenter.x - (deadZoneWidth >> 1);
	cameraDeadzone.max.x = deadZoneCenter.x + (deadZoneWidth >> 1);
	cameraDeadzone.min.y = deadZoneCenter.y - (deadZoneHeight >> 1);
	cameraDeadzone.max.y = deadZoneCenter.y + (deadZoneHeight >> 1);

	updateCamera();

	//We force to update the whole layer in order to prevent wrong tile being loaded depending on the position
	MAP_scrollToEx(levelmap1, cameraPosition.x, cameraPosition.y, TRUE);
}

void updateCamera() {
	int player_x_map=game_state.player.x;
	int player_y_map=game_state.player.y;
	int player_x_screen=player_x_map-cameraPosition.x;
	int player_y_screenp=player_y_map-cameraPosition.y;

	int new_camera_x;
	int new_camera_y;	
	if(player_x_screen >  cameraDeadzone.max.x)
	{
		new_camera_x= player_x_screen-cameraDeadzone.max.x;
	}
	else if(player_x_screen <  cameraDeadzone.min.x)
	{
		new_camera_x= player_x_screen-cameraDeadzone.min.x;
	}
	else new_camera_x=cameraPosition.x;
	if(new_camera_x<0)
	{
		new_camera_x=0;
	}else if(new_camera_x>MAP_WIDTH-325)
	{
		new_camera_x=MAP_WIDTH-325;
	}
	if((cameraPosition.x!=new_camera_x) ||(cameraPosition.y!=new_camera_y))
	{
		cameraPosition.x=new_camera_x;
		cameraPosition.y=new_camera_y;
		MAP_scrollTo(levelmap1, cameraPosition.x, cameraPosition.y);		 
	}
	else {
	SPR_setPosition(game_state.player.sprite, game_state.player.x-new_camera_x, game_state.player.y-new_camera_y);
	}
	//Finally we update the position of the camera
	
}