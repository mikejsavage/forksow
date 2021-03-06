#include "cgame/cg_local.h"
#include "client/renderer/srgb.h"

bool CG_IsAlly( int team ) {
	if( team == TEAM_ALLY || team == TEAM_ENEMY )
		return team == TEAM_ALLY;

	int myteam = cg.predictedPlayerState.team;
	if( myteam == TEAM_SPECTATOR )
		return team == TEAM_ALPHA;
	if( myteam == TEAM_PLAYERS )
		return false;
	return team == myteam;
}

RGB8 CG_TeamColor( int team ) {
	if( team == TEAM_PLAYERS )
		return RGB8( 255, 255, 255 );

	const RGB8 * colors = cg_colorBlind != NULL ? ( cg_colorBlind->integer ? COLORBLIND_TEAM_COLORS : TEAM_COLORS ) : TEAM_COLORS;
	return CG_IsAlly( team ) ? colors[ 0 ] : colors[ 1 ];
}

Vec4 CG_TeamColorVec4( int team ) {
	return Vec4( sRGBToLinear( CG_TeamColor( team ) ), 1.0f );
}
