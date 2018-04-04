#pragma once
#include "SDK.h"

#define FAKE_LATENCY_AMOUNT 0.046875f //here fake latecy
#define LAG_COMPENSATION_EPS_SQR ( 0.1f * 0.1f )
#define LAG_COMPENSATION_ERROR_EPS_SQR ( 4.0f * 4.0f )

struct CIncomingSequence
{
	CIncomingSequence::CIncomingSequence(int instate, int outstate, int seqnr, float time)
	{
		inreliablestate = instate;
		outreliablestate = outstate;
		sequencenr = seqnr;
		curtime = time;
	}
	int inreliablestate;
	int outreliablestate;
	int sequencenr;
	float curtime;
};

struct lbyRecords
{
	int tick_count;
	float lby;
	Vector headPosition;
};
struct backtrackData
{
	float simtime;
	Vector hitboxPos;
};

class BackTrack
{
	int latest_tick;
	bool IsTickValid(int tick);
	void UpdateRecord(int i);
public:
	lbyRecords records[64];
	bool RunLBYBackTrack(int i, CInput::CUserCmd* cmd, Vector& aimPoint);
	void Update(int tick_count);
	void legitBackTrack(CInput::CUserCmd* cmd, C_BaseEntity* pLocal);
	void RageBackTrack(CInput::CUserCmd* cmd, C_BaseEntity* pLocal);
	void AddLatencyToNetchan(INetChannel * netchan, float Latency);
};

extern backtrackData headPositions[64][12];

extern BackTrack* backtracking;






