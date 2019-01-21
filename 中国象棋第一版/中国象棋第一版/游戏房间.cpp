#include "游戏房间.h"
using namespace 中国象棋第一版;

void 游戏房间::UdateRoomInfo(S_TableInfo STs[10]) {
	for (int i = 0; i < 10; i++) {
		PictureBox ^p = (PictureBox ^)this->Controls->Find("Table" + (i + 1).ToString() + "_1", true)[0];
		LoadHeadPic(p, gcnew String(STs[i].spi[0].HeadPictureName));
		p = (PictureBox ^)this->Controls->Find("Table" + (i + 1).ToString() + "_2", true)[0];
		LoadHeadPic(p, gcnew String(STs[i].spi[1].HeadPictureName));
	}
}

void 游戏房间::UpdateTable(S_TableInfo &sti) {
	g_pi.NowTableId = sti.TableId;
	PictureBox^Left = (PictureBox ^)this->Controls->Find("Table" + (g_pi.NowTableId + 1).ToString() + "_1", true)[0];
	PictureBox^Right = (PictureBox ^)this->Controls->Find("Table" + (g_pi.NowTableId + 1).ToString() + "_2", true)[0];
	LoadHeadPic(Left, gcnew String(sti.spi[0].HeadPictureName));
	LoadHeadPic(Right, gcnew String(sti.spi[1].HeadPictureName));
}
