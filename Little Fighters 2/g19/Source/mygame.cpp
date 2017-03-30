
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
namespace game_framework
{
	CPlayerA::CPlayerA()
	{
		Initialize();
	}

	int CPlayerA::GetX1()
	{
		return x;
	}

	int CPlayerA::GetY1()
	{
		return y;
	}

	int CPlayerA::GetX2()
	{
		return x + playerA_pic1.Width();
	}

	int CPlayerA::GetY2()
	{
		return y + playerA_pic1.Height();
	}

	int CPlayerA::Getb1(){
		return b1;
	}

	int CPlayerA::Getm1(){
		return m1;
	}

	int CPlayerA::GetWeaponX(){
		return weaponX;
	}

	int CPlayerA::GetWeapon2X(){
		return weapon2X;
	}

	int CPlayerA::GetWeapon3X(){
		return weapon3X;
	}

	int CPlayerA::GetWeapon4X(){
		return weapon4X;
	}

	int CPlayerA::GetWeaponY(){
		return weaponY - 90;
	}

	int CPlayerA::GetWeapon2Y(){
		return weapon2Y - 90;
	}

	int CPlayerA::GetWeapon3Y(){
		return weapon3Y - 90;
	}

	int CPlayerA::GetWeapon4Y(){
		return weapon4Y - 90;
	}

	int CPlayerA::GetWeaponBallX(){
		return weaponBallX;
	}

	int CPlayerA::GetWeaponBallY(){
		return weaponBallY;
	}

	int CPlayerA::Getweapon_Continue1X(){
		return weapon_Continue1X;
	}

	int CPlayerA::Getweapon_Continue1Y(){
		return weapon_Continue1Y;
	}

	int CPlayerA::Getweapon_Continue2X(){
		return weapon_Continue2X;
	}

	int CPlayerA::Getweapon_Continue2Y(){
		return weapon_Continue2Y;
	}

	int CPlayerA::Getweapon_Continue3X(){
		return weapon_Continue3X;
	}

	int CPlayerA::Getweapon_Continue3Y(){
		return weapon_Continue3Y;
	}

	int CPlayerA::Getweapon_Continue4X(){
		return weapon_Continue4X;
	}

	int CPlayerA::Getweapon_Continue4Y(){
		return weapon_Continue4Y;
	}

	int CPlayerA::Getweapon_Continue5X(){
		return weapon_Continue5X;
	}

	int CPlayerA::Getweapon_Continue5Y(){
		return weapon_Continue5Y;
	}

	int CPlayerA::GetWeaponNumber(){
		return weaponNumber;
	}

	int  CPlayerA::GetX_forTool(int t1, int t2, int t3){
		if (t1 == 1){
			if (weaponing)	return weaponX;
			if (isDefend)	return x + 10;
		}

		return x;
	}


	int  CPlayerA::GetY_forTool(int t1, int t2, int t3){
		if (t1 == 1){
			if (isDefend){
				if (dir == 1)	return y - 30;
			}
		}
		return y;
	}



	bool CPlayerA::WhetherJump(){
		return isJump;
	}

	bool CPlayerA::WhetherLand(){
		return isLand;
	}

	bool CPlayerA::WhetherMoving(){
		if (isMovingLeft || isMovingRight)	return true;
		return false;
	}

	bool CPlayerA::WhetherRuning(){
		if (isRun)	return true;
		return false;
	}

	bool CPlayerA::WhetherDLA(){
		if (isDLA)	return true;
		return false;
	}

	bool CPlayerA::WhetherDRA(){
		if (isDRA)	return true;
		return false;
	}

	int CPlayerA::Get_DUA_X(){
		if (!DUA_bloodMinus)	return x;
		else return -300;
	}

	int CPlayerA::Get_DUA_Y(){
		if (!DUA_bloodMinus)	return y;
		else return -300;
	}

	void CPlayerA::Initialize()
	{
		const int X_POS = 300;
		const int Y_POS = 240;
		b1 = 66;
		m1 = 66;
		counter1 = counter2 = counter3 = counter4 = 35;
		A_monaRecover = A_bloodRecover = 0;
		x = X_POS;
		y = Y_POS;
		dir = 2;
		weaponNumber = 1;
		DUA_step = 1;
		A_DUAcounter = 0;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isAttack = weaponing = isJump = isLand = isDefend = isRun = false;
		isDLJ = isDRJ = isDLA = isDRA = isDUA = hasTool = false;
		DUA_bloodMinus = true;
	}

	void CPlayerA::LoadBitmap()
	{
		playerA_pic1.AddBitmap(IDB_playerA_2, RGB(255, 255, 255));
		playerA_pic1.AddBitmap(IDB_A_breath_L, RGB(255, 255, 255));
		playerA_pic2.AddBitmap(IDB_playerA, RGB(255, 255, 255));
		playerA_pic2.AddBitmap(IDB_A_breath_R, RGB(255, 255, 255));

		playerA_walkL.AddBitmap(IDB_playerA_2, RGB(255, 255, 255));
		playerA_walkL.AddBitmap(IDB_A_walk_L, RGB(255, 255, 255));
		playerA_walkR.AddBitmap(IDB_A_walk_R, RGB(255, 255, 255));
		playerA_walkR.AddBitmap(IDB_playerA, RGB(255, 255, 255));

		attackA_L.AddBitmap(IDB_AttackAL, RGB(255, 255, 255));
		attackA_L.AddBitmap(IDB_AttackA_L_2, RGB(255, 255, 255));
		attackA_R.AddBitmap(IDB_AttackAR, RGB(255, 255, 255));
		attackA_R.AddBitmap(IDB_AttackA_R_2, RGB(255, 255, 255));

		weapon.AddBitmap(IDB_Bweapon, RGB(255, 255, 255));

		jumpA_L.AddBitmap(IDB_jumpA_L, RGB(255, 255, 255));
		jumpA_R.AddBitmap(IDB_jumpA_R, RGB(255, 255, 255));

		defendA_L.AddBitmap(IDB_defendA_L, RGB(255, 255, 255));
		defendA_R.AddBitmap(IDB_defendA_R, RGB(255, 255, 255));

		runA_L.AddBitmap(IDB_runA_L, RGB(255, 255, 255));
		runA_L.AddBitmap(IDB_runA_L_2, RGB(255, 255, 255));
		runA_R.AddBitmap(IDB_runA_R, RGB(255, 255, 255));
		runA_R.AddBitmap(IDB_runA_R_2, RGB(255, 255, 255));

		AweaponBall_L.AddBitmap(IDB_AweaponBall_L, RGB(255, 255, 255));
		AweaponBall_R.AddBitmap(IDB_AweaponBall_R, RGB(255, 255, 255));

		Aweapon_Continue1_L.AddBitmap(IDB_Aweapon_Continue_L, RGB(255, 255, 255));
		Aweapon_Continue1_R.AddBitmap(IDB_Aweapon_Continue_R, RGB(255, 255, 255));
		Aweapon_Continue2_L.AddBitmap(IDB_Aweapon_Continue_L, RGB(255, 255, 255));
		Aweapon_Continue2_R.AddBitmap(IDB_Aweapon_Continue_R, RGB(255, 255, 255));
		Aweapon_Continue3_L.AddBitmap(IDB_Aweapon_Continue_L, RGB(255, 255, 255));
		Aweapon_Continue3_R.AddBitmap(IDB_Aweapon_Continue_R, RGB(255, 255, 255));
		Aweapon_Continue4_L.AddBitmap(IDB_Aweapon_Continue_L, RGB(255, 255, 255));
		Aweapon_Continue4_R.AddBitmap(IDB_Aweapon_Continue_R, RGB(255, 255, 255));
		Aweapon_Continue5_L.AddBitmap(IDB_Aweapon_Continue_L, RGB(255, 255, 255));
		Aweapon_Continue5_R.AddBitmap(IDB_Aweapon_Continue_R, RGB(255, 255, 255));

		ASkill1_L.AddBitmap(IDB_Askill1_L, RGB(255, 255, 255));
		ASkill2_L.AddBitmap(IDB_Askill2_L, RGB(255, 255, 255));
		ASkill3_L.AddBitmap(IDB_Askill3, RGB(255, 255, 255));

		ASkill1_R.AddBitmap(IDB_Askill1_R, RGB(255, 255, 255));
		ASkill2_R.AddBitmap(IDB_Askill2_R, RGB(255, 255, 255));
		ASkill3_R.AddBitmap(IDB_Askill3, RGB(255, 255, 255));
	}

	void CPlayerA::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CPlayerA::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CPlayerA::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CPlayerA::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CPlayerA::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	void CPlayerA::Setb1(int nx){
		b1 = b1 + nx;

	}
	void CPlayerA::Setm1(int nx){
		m1 = m1 + nx;
	}

	void CPlayerA::SetDir(int _dir){
		dir = _dir;
	}

	void CPlayerA::SetAttack(bool flag){
		isAttack = flag;
		if (flag == true){
			weaponing = true;
			weaponDir = dir;
		}
	}

	void CPlayerA::SetJump(bool flag){
		isJump = flag;
	}

	void CPlayerA::SetOriginalY(int yPos){
		jumpY = yPos;
	}

	void CPlayerA::SetDefend(bool flag){
		isDefend = flag;
	}

	void CPlayerA::SetRun(bool flag){
		isRun = flag;
	}



	void CPlayerA::SetWeaponNumber(int num){
		weaponNumber = num;
	}

	void CPlayerA::SetTool(bool flag){
		hasTool = flag;
	}

	void CPlayerA::OnMove()
	{
		const int STEP_SIZE = 4;

		if (isMovingLeft&&x >= 0){
			x -= STEP_SIZE;
			playerA_walkL.SetTopLeft(x, y + 135);
			playerA_walkL.OnMove(); playerA_walkL.OnMove();
		}
		if (isMovingRight&&x <= 760)
		{
			x += STEP_SIZE;
			playerA_walkR.SetTopLeft(x, y + 135);
			playerA_walkR.OnMove(); playerA_walkR.OnMove();
		}
		if (isMovingUp&&y >= 150)
			y -= STEP_SIZE;
		if (isMovingDown&&y <= 350)
			y += STEP_SIZE;

		///////////////////////此段為撰寫虛擬武器/////////////////////////////

		weapon.SetTopLeft(x - 12, y + 135);
		attackA_L.SetTopLeft(x - 5, y + 135);
		attackA_R.SetTopLeft(x - 30, y + 135);
		if (isAttack || weaponing == true){
			if (weaponDir == 1){								//面向左邊

				if (isAttack){
					weapon.SetTopLeft(x - 12, y + 135);   // x - 12 才有剛好出現在手上的感覺
					weaponX = x;
					weaponY = y + 135;
				}
				if (weaponing && weaponDir == 1){	//按了Attack之後即使立刻放手,飛刀依然要繼續飛一下
					weapon.SetTopLeft(weaponX - 12, weaponY);
					weaponX = weaponX - 12;

					//下面這行是判斷 到了一定距離之後使其開始往下掉 看上去有物理效果

					//判斷射出一定距離之後將飛鏢位置設到視窗外，看起來會像消失
					if ((weaponX < playerA_pic1.Left() - 45)){
						weapon.SetTopLeft(-200, -200);
						weaponing = false;
						weaponX = x; weaponY = y;

					}
				}

			}

			if (weaponDir == 2){ //面向右邊
				//	attackB_R.SetTopLeft(x, y + 135);			//(面向右邊)攻擊的圖片
				if (isAttack){
					weapon.SetTopLeft(x + 12, y + 145);  // x + 12 才有剛好出現在手上的感覺
					weaponX = x + 12;
					weaponY = y + 145;
				}
				if (weaponing&&weaponDir == 2){	//按了Attack之後即使立刻放手,飛刀依然要繼續飛一下
					weapon.SetTopLeft(weaponX + 12, weaponY);
					weaponX = weaponX + 12;



					//判斷射出一定距離之後將飛鏢位置設到視窗外，看起來會像消失
					if (weaponX > playerA_pic2.Left() + 75){
						weapon.SetTopLeft(-200, -200);
						weaponing = false;
						weaponX = x; weaponY = y;
					}



					////////////////////
				}
			}
		}

		///////////////////////////虛擬武器結束/////////////////////////////


		//以下兩個都在處理跳躍動作,isJump是往上跳,isLand是跳完要掉下來的動作
		if (isJump){
			if (y < jumpY - 72){
				isJump = false;
				isLand = true;
			}
			jumpA_L.SetTopLeft(x, y + 135);
			jumpA_R.SetTopLeft(x, y + 135);
			y = y - 12;
		}
		if (isLand){
			if (y == jumpY)
				isLand = false;
			else{
				jumpA_L.SetTopLeft(x, y + 135);
				jumpA_R.SetTopLeft(x, y + 135);
				if (y < 350) y = y + 12;
				else isLand = false;
			}
		}

		if (isDefend){
			if (dir == 1)	defendA_L.SetTopLeft(x, y + 135);
			else			defendA_R.SetTopLeft(x, y + 135);
		}
		if (isRun){
			if (dir == 1){
				runA_L.SetTopLeft(x, y + 135);
				if (x >= 0)	x -= 6;
				runA_L.OnMove();				// 聽說要這樣才會換圖
				runA_L.OnMove();				// 覺得他跑太慢了應該多換幾次才對
				runA_L.OnMove();				// 覺得他跑太慢了應該多換幾次才對
				runA_L.OnMove();				// 覺得他跑太慢了應該多換幾次才對
			}
			else{
				runA_R.SetTopLeft(x, y + 135);
				if (x <= 760) x += 6;
				runA_R.OnMove();				//聽說要這樣才會換圖
				runA_R.OnMove();				// 覺得他跑太慢了應該多換幾次才對
				runA_R.OnMove();				// 覺得他跑太慢了應該多換幾次才對
				runA_R.OnMove();				// 覺得他跑太慢了應該多換幾次才對
			}
		}

		playerA_pic1.SetTopLeft(x, y + 135);
		playerA_pic2.SetTopLeft(x, y + 135);
		playerA_pic1.OnMove();
		playerA_pic2.OnMove();

		//////////////////////////////此處處理技能//////////////////////////////////////
		if (isDefend)              //1.防
			counter1 = 0;

		if (counter1 < 35){
			counter1++;
			if (isMovingRight)    //2. 防右
				counter2 = 0;

			if (isMovingLeft)    //2. 防左
				counter3 = 0;

			if (isMovingUp)
				counter4 = 0;   //2.防上

		}

		if (counter1 + counter4 < 35){
			counter4++;
			{
				if (isAttack && m1 > 6){		// 防上攻!
					CAudio::Instance()->Play(AUDIO_DUA);
					m1 = m1 - 6;
					counter4 = 35;
					ASkill1_L.SetTopLeft(x - 10, y + 125);
					ASkill1_R.SetTopLeft(x + 10, y + 125);
					ASkill2_L.SetTopLeft(x - 30, y + 90);
					ASkill2_R.SetTopLeft(x + 30, y + 90);
					ASkill3_L.SetTopLeft(x - 50, y + 125);
					ASkill3_R.SetTopLeft(x + 50, y + 125);
					isDUA = true;

					if (dir == 1){
						x -= 50;
						playerA_pic1.SetTopLeft(x, y);
					}
					if (dir == 2){
						x += 50;
						playerA_pic2.SetTopLeft(x, y);
					}
				}
			}
		}

		if (counter2 + counter1 < 35){
			counter2++;
			if (isAttack && m1 > 2){           //防右攻!
				CAudio::Instance()->Play(AUDIO_energyball);
				//這裡放上招式的設定
				m1 = m1 - 2;
				counter2 = 35;
				isDRA = true;
				weapon_Continue1X = x; weapon_Continue1Y = y + 135;
				weapon_Continue2X = x; weapon_Continue2Y = y + 135;
				weapon_Continue3X = x; weapon_Continue3Y = y + 135;
				weapon_Continue4X = x; weapon_Continue4Y = y + 135;
				weapon_Continue5X = x; weapon_Continue5Y = y + 135;
			}

			if (isJump && m1 > 10){           //防右跳!
				CAudio::Instance()->Play(AUDIO_energyball2);
				//這裡放上招式的設定
				m1 = m1 - 10;
				counter2 = 35;
				isDRJ = true;
				weaponBallX = x; weaponBallY = y + 135;
			}
		}

		if (counter3 + counter1 < 35){
			counter3++;
			if (isAttack && m1 > 2){           //防左攻!
				CAudio::Instance()->Play(AUDIO_energyball);
				//這裡放上招式的設定
				m1 = m1 - 2;
				counter3 = 35;
				isDLA = true;

				weapon_Continue1X = x - 60; weapon_Continue1Y = y + 135;
				weapon_Continue2X = x - 60; weapon_Continue2Y = y + 135;
				weapon_Continue3X = x - 60; weapon_Continue3Y = y + 135;
				weapon_Continue4X = x - 60; weapon_Continue4Y = y + 135;
				weapon_Continue5X = x - 60; weapon_Continue5Y = y + 135;
			}

			if (isJump && m1 > 10){           //防左跳!
				CAudio::Instance()->Play(AUDIO_energyball2);
				//這裡放上招式的設定
				m1 = m1 - 10;
				counter3 = 35;
				isDLJ = true;
				weaponBallX = x; weaponBallY = y + 135;
			}
		}

		/*if (counter4 + counter1 < 35){
		counter4++;
		if (isAttack && m1 > 20){           //防下攻!
		//這裡放上招式的設定
		//m1 = m1 - 20;
		//counter4 = 35;
		}
		}*/

		/////////////////// 觸發防前(左/右)跳技能 ///////////////////
		if (isDLJ){
			AweaponBall_L.SetTopLeft(weaponBallX, weaponBallY);
			weaponBallX -= 15;
			if (weaponBallX < -200)
				isDLJ = false;
		}
		else if (isDRJ){
			AweaponBall_R.SetTopLeft(weaponBallX, weaponBallY);
			weaponBallX += 15;
			if (weaponBallX > 800)
				isDRJ = false;
		}

		/////////////////// 觸發防前(左/右)攻技能 ///////////////////
		if (isDLA){

			if (weaponNumber >= 1){
				Aweapon_Continue1_L.SetTopLeft(weapon_Continue1X, weapon_Continue1Y);
				weapon_Continue1X -= 15;
			}
			if (weaponNumber >= 2){
				Aweapon_Continue2_L.SetTopLeft(weapon_Continue2X, weapon_Continue2Y);
				weapon_Continue2X -= 15;
			}
			if (weaponNumber >= 3){
				Aweapon_Continue3_L.SetTopLeft(weapon_Continue3X, weapon_Continue3Y);
				weapon_Continue3X -= 15;
			}
			if (weaponNumber >= 4){
				Aweapon_Continue4_L.SetTopLeft(weapon_Continue4X, weapon_Continue4Y);
				weapon_Continue4X -= 15;
			}

			if (weaponNumber >= 5){
				Aweapon_Continue5_L.SetTopLeft(weapon_Continue5X, weapon_Continue5Y);
				weapon_Continue5X -= 15;
			}

			if (weaponNumber == 1 && weapon_Continue1X < -100)
				isDLA = false;
			if (weaponNumber == 2 && weapon_Continue2X < -100)
				isDLA = false;
			if (weaponNumber == 3 && weapon_Continue3X < -100)
				isDLA = false;
			if (weaponNumber == 4 && weapon_Continue4X < -100)
				isDLA = false;
			if (weaponNumber == 5 && weapon_Continue5X < -100)
				isDLA = false;
		}
		else if (isDRA){

			if (weaponNumber >= 1){
				Aweapon_Continue1_R.SetTopLeft(weapon_Continue1X, weapon_Continue1Y);
				weapon_Continue1X += 15;
			}
			if (weaponNumber >= 2){
				Aweapon_Continue2_R.SetTopLeft(weapon_Continue2X, weapon_Continue2Y);
				weapon_Continue2X += 15;
			}
			if (weaponNumber >= 3){
				Aweapon_Continue3_R.SetTopLeft(weapon_Continue3X, weapon_Continue3Y);
				weapon_Continue3X += 15;
			}
			if (weaponNumber >= 4){
				Aweapon_Continue4_R.SetTopLeft(weapon_Continue4X, weapon_Continue4Y);
				weapon_Continue4X += 15;
			}

			if (weaponNumber >= 5){
				Aweapon_Continue5_R.SetTopLeft(weapon_Continue5X, weapon_Continue5Y);
				weapon_Continue5X += 15;
			}

			if (weaponNumber == 1 && weapon_Continue1X > 800)
				isDRA = false;
			if (weaponNumber == 2 && weapon_Continue2X > 800)
				isDRA = false;
			if (weaponNumber == 3 && weapon_Continue3X > 800)
				isDRA = false;
			if (weaponNumber == 4 && weapon_Continue4X > 800)
				isDRA = false;
			if (weaponNumber == 5 && weapon_Continue5X > 800)
				isDRA = false;
		}

		//////////////////////////////處理技能結束//////////////////////////////////////

		// 自動回魔與自動回血
		if (!isMovingDown && !isMovingLeft && !isMovingRight && !isMovingUp && !isAttack && !weaponing && !isJump && !isLand){ //站著不動的狀況
			A_monaRecover++; A_bloodRecover++;
			if (A_monaRecover == 60){ //大約2秒
				if (m1 <= 66) m1 += 1;
				A_monaRecover = 0;
			}
			if (A_bloodRecover == 90){ //大約3秒
				if (b1 <= 66) b1 += 1;
				A_bloodRecover = 0;
			}
		}

		attackA_L.OnMove();
		attackA_R.OnMove();

	}//for -> OnMove()

	void CPlayerA::OnShow()
	{
		//////////////// 此段為測試是否有虛擬武器的運作
		if (dir == 1){
			if (isAttack){
				attackA_L.OnShow();
			}
			else if (weaponing){
				weapon.OnMove(); //weapon.OnShow();
			}
		}

		else if (dir == 2){
			if (isAttack)
				attackA_R.OnShow();
			else if (weaponing){
				weapon.OnMove(); //weapon.OnShow();
			}
		}

		///////////// 其他動作判定 //////////////////

		if (dir == 1){
			if (isAttack){
				CAudio::Instance()->Play(AUDIO_punch);
				attackA_L.OnShow();

			}
			else if (isJump || isLand){

				CAudio::Instance()->Play(AUDIO_jump);
				jumpA_L.OnShow();
			}
			else if (isDefend){
				defendA_L.OnShow();
			}
			else if (isRun){
				CAudio::Instance()->Play(AUDIO_run);
				runA_L.OnShow();

			}
			else if (isDUA){ //防上攻
				if (DUA_step == 1){
					ASkill1_L.OnShow();
					A_DUAcounter++;
					if (A_DUAcounter > 7){
						DUA_step++;
						A_DUAcounter = 0;
					}
				}
				if (DUA_step == 2){
					ASkill2_L.OnShow();
					A_DUAcounter++;
					if (A_DUAcounter > 7){
						DUA_step++;
						A_DUAcounter = 0;
					}
				}
				if (DUA_step == 3){
					ASkill3_L.OnShow();
					A_DUAcounter++;
					if (A_DUAcounter > 7){
						DUA_step++;
						A_DUAcounter = 0;
					}
				}
				if (DUA_step == 4){
					DUA_step = 1;
					isDUA = false;
					playerA_pic1.OnShow();
				}
			}
			else if (isMovingLeft)
			{
				playerA_walkL.OnShow();
			}
			else{
				playerA_pic1.OnShow();
			}
		}
		if (dir == 2){
			if (isAttack){
				CAudio::Instance()->Play(AUDIO_punch);
				attackA_R.OnShow();

			}
			else if (isJump || isLand){

				CAudio::Instance()->Play(AUDIO_jump);
				jumpA_R.OnShow();
			}
			else if (isDefend){
				defendA_R.OnShow();
			}
			else if (isRun){
				CAudio::Instance()->Play(AUDIO_run);
				runA_R.OnShow();
			}
			else if (isDUA){	// 防上攻
				if (DUA_step == 1){
					ASkill1_R.OnShow();
					A_DUAcounter++;
					if (A_DUAcounter > 7){
						DUA_step++;
						A_DUAcounter = 0;
					}
				}
				if (DUA_step == 2){
					ASkill2_R.OnShow();
					A_DUAcounter++;
					if (A_DUAcounter > 7){
						DUA_step++;
						A_DUAcounter = 0;
					}
				}
				if (DUA_step == 3){
					ASkill3_R.OnShow();
					A_DUAcounter++;
					if (A_DUAcounter > 7){
						DUA_step++;
						A_DUAcounter = 0;
					}
				}
				if (DUA_step == 4){
					DUA_step = 1;
					isDUA = false;
					playerA_pic2.OnShow();
				}
			}
			else if (isMovingRight){
				playerA_walkR.OnShow();
			}
			else{
				playerA_pic2.OnShow();
			}
		}

		///// 觸發 防前(左/右)跳 技能時的氣功球 /////
		if (isDLJ)	AweaponBall_L.OnShow();
		if (isDRJ)	AweaponBall_R.OnShow();

		///// 觸發 防前(左/右)攻 技能時的連彈 /////
		if (isDLA){
			Aweapon_Continue1_L.OnShow();
			if (weaponNumber >= 2)	Aweapon_Continue2_L.OnShow();
			if (weaponNumber >= 3)	Aweapon_Continue3_L.OnShow();
			if (weaponNumber >= 4)	Aweapon_Continue4_L.OnShow();
			if (weaponNumber >= 5)	Aweapon_Continue5_L.OnShow();
		}
		if (isDRA)	{
			Aweapon_Continue1_R.OnShow();
			if (weaponNumber >= 2)	Aweapon_Continue2_R.OnShow();
			if (weaponNumber >= 3)	Aweapon_Continue3_R.OnShow();
			if (weaponNumber >= 4)	Aweapon_Continue4_R.OnShow();
			if (weaponNumber >= 5)	Aweapon_Continue5_R.OnShow();
		}
	}

	int CPlayerA::GetDir(){
		return dir;
	}








	CPlayerB::CPlayerB()
	{
		Initialize();
	}

	int CPlayerB::GetX1()
	{
		return x;
	}

	int CPlayerB::GetY1()
	{
		return y;
	}

	int CPlayerB::GetX2()
	{
		if (dir == 1)
			return x + playerB_pic_left.Width();
		else
			return x + playerB_pic_right.Width();

	}

	int CPlayerB::GetY2()
	{
		if (dir == 1)
			return y + playerB_pic_left.Height();
		else
			return y + playerB_pic_right.Height();
	}

	int CPlayerB::GetWeaponX(){
		return weaponX;
	}

	int CPlayerB::GetWeapon2X(){
		return weapon2X;
	}

	int CPlayerB::GetWeapon3X(){
		return weapon3X;
	}

	int CPlayerB::GetWeapon4X(){
		return weapon4X;
	}

	int CPlayerB::GetWeapon5X(){
		return weapon5X;
	}

	int CPlayerB::GetWeaponY(){
		return weaponY - 90;
	}

	int CPlayerB::GetWeapon2Y(){
		return weapon2Y - 90;
	}

	int CPlayerB::GetWeapon3Y(){
		return weapon3Y - 90;
	}

	int CPlayerB::GetWeapon4Y(){
		return weapon4Y - 90;
	}

	int CPlayerB::GetWeapon5Y(){
		return weapon5Y - 90;
	}

	int CPlayerB::Getb2(){
		return b2;
	}

	int CPlayerB::Getm2(){
		return m2;
	}

	int CPlayerB::GetDir(){
		return dir;
	}

	bool CPlayerB::WhetherJump(){
		return isJump;
	}

	bool CPlayerB::WhetherLand(){
		return isLand;
	}

	bool CPlayerB::WhetherMoving(){
		if (isMovingLeft || isMovingRight)	return true;
		return false;
	}

	bool CPlayerB::WhetherRuning(){
		if (isRun)	return true;
		return false;
	}

	void CPlayerB::WeaponMissing(){
		missing = true;
		weaponing = false;
		weapon.SetTopLeft(-200, -200);
	}

	void CPlayerB::Initialize()
	{
		const int X_POS = 360;
		const int Y_POS = 240;
		x = X_POS;
		y = Y_POS;
		b2 = 66;
		m2 = 66;
		counter1 = counter2 = counter3 = counter4 = DLJ_Counter = DRJ_Counter = 0;
		B_monaRecover = B_bloodRecover = 0;
		dir = 1;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isAttack = weaponing = isJump = isLand = isDefend = isRun = missing = hidden = false;
		isDLA = isDRA = isDLJ = isDRJ = hasTool = false;

	}

	void CPlayerB::LoadBitmap()
	{
		playerB_pic_left.AddBitmap(IDB_playerB, RGB(255, 255, 255));
		playerB_pic_left.AddBitmap(IDB_B_breath_L, RGB(255, 255, 255));
		playerB_pic_right.AddBitmap(IDB_playerB_2, RGB(255, 255, 255));
		playerB_pic_right.AddBitmap(IDB_B_breath_R, RGB(255, 255, 255));

		playerB_walkL.AddBitmap(IDB_playerB, RGB(255, 255, 255));
		playerB_walkL.AddBitmap(IDB_B_walk_L, RGB(255, 255, 255));
		playerB_walkR.AddBitmap(IDB_B_walk_R, RGB(255, 255, 255));
		playerB_walkR.AddBitmap(IDB_playerB_2, RGB(255, 255, 255));

		attackB_L.AddBitmap(IDB_AttackBL, RGB(255, 255, 255));
		attackB_R.AddBitmap(IDB_AttackBR, RGB(255, 255, 255));

		weapon.AddBitmap(IDB_Bweapon, RGB(255, 255, 255));
		weapon2.AddBitmap(IDB_Bweapon, RGB(255, 255, 255));
		weapon3.AddBitmap(IDB_Bweapon, RGB(255, 255, 255));
		weapon4.AddBitmap(IDB_Bweapon, RGB(255, 255, 255));
		weapon5.AddBitmap(IDB_Bweapon, RGB(255, 255, 255));

		jumpB_L.AddBitmap(IDB_jumpB_L, RGB(255, 255, 255));
		jumpB_R.AddBitmap(IDB_jumpB_R, RGB(255, 255, 255));

		defendB_L.AddBitmap(IDB_defendB_L, RGB(255, 255, 255));
		defendB_R.AddBitmap(IDB_defendB_R, RGB(255, 255, 255));

		//嫌他跑太慢,多載幾次
		runB_L.AddBitmap(IDB_runB_L, RGB(255, 255, 255));
		runB_L.AddBitmap(IDB_runB_L_2, RGB(255, 255, 255));

		runB_R.AddBitmap(IDB_runB_R, RGB(255, 255, 255));
		runB_R.AddBitmap(IDB_runB_R_2, RGB(255, 255, 255));

		B_DLJ.AddBitmap(IDB_B_DLJ1, RGB(255, 255, 255));
		B_DLJ.AddBitmap(IDB_B_DLJ2, RGB(255, 255, 255));
		B_DRJ.AddBitmap(IDB_B_DRJ1, RGB(255, 255, 255));
		B_DRJ.AddBitmap(IDB_B_DRJ2, RGB(255, 255, 255));


	}

	void CPlayerB::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CPlayerB::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CPlayerB::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CPlayerB::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CPlayerB::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}


	void CPlayerB::Setb2(int nx){
		b2 = b2 + nx;
	}

	void CPlayerB::Setm2(int nx){
		m2 = m2 + nx;
	}

	void CPlayerB::SetDir(int _dir){
		dir = _dir;
	}

	void CPlayerB::SetAttack(bool flag){
		isAttack = flag;
		if (flag == true){
			weaponing = true;
			weaponDir = dir;
		}
	}

	void CPlayerB::SetJump(bool flag){
		isJump = flag;
	}

	void CPlayerB::SetOriginalY(int yPos){
		jumpY = yPos;
	}

	void CPlayerB::SetDefend(bool flag){
		isDefend = flag;
	}

	void CPlayerB::SetRun(bool flag){
		isRun = flag;
	}

	void CPlayerB::SetTool(bool flag){
		hasTool = flag;
	}

	int  CPlayerB::GetX_forTool(int t1, int t2, int t3){
		if (t1 == 1){
			if (weaponing)
			{
				if (dir == 1){
					if (weaponX > x - 20)	return weaponX;
				}
				if (dir == 2){
					if (weaponX < x + 50)	return weaponX;
				}
			}
			if (isDefend)	return x + 10;
		}

		return x;
	}


	int  CPlayerB::GetY_forTool(int t1, int t2, int t3){
		if (t1 == 1){
			if (isDefend)	return y - 30;
			if (weaponing && dir == 2 && weaponX < x + 50)	return y - 30;
			if (weaponing && dir == 1 && weaponX > x - 20)	return y - 30;
		}
		return y;
	}

	void CPlayerB::OnMove()
	{
		const int STEP_SIZE = 5;

		if (isMovingLeft&&x >= -60){
			x -= STEP_SIZE;
			playerB_walkL.SetTopLeft(x, y + 135);
			playerB_walkL.OnMove(); playerB_walkL.OnMove();
		}
		if (isMovingRight&&x <= 700){
			x += STEP_SIZE;
			playerB_walkR.SetTopLeft(x, y + 135);
			playerB_walkR.OnMove(); playerB_walkR.OnMove();
		}
		if (isMovingUp&&y >= 150)
			y -= STEP_SIZE;
		if (isMovingDown&&y <= 350)
			y += STEP_SIZE;

		//	if (!hidden){
		if (isDRA){
			playerB_pic_right.SetTopLeft(x, y);
			weapon.SetTopLeft(weaponX, weaponY);
			weapon2.SetTopLeft(weapon2X, weapon2Y);
			weapon3.SetTopLeft(weapon3X, weapon3Y);
			weapon4.SetTopLeft(weapon4X, weapon4Y);
			weapon5.SetTopLeft(weapon5X, weapon5Y);
			weaponX += 8; weapon2X += 10; weapon3X += 13; weapon4X += 9; weapon5X += 8;
			weaponY += 2; weapon2Y += 1;  weapon4Y -= 1;  weapon5Y -= 2;

			if ((weapon3X > playerB_pic_left.Left() + 230)){
				isDRA = false;
				weapon.SetTopLeft(-200, -200);
				weapon2.SetTopLeft(-200, -200);
				weapon3.SetTopLeft(-200, -200);
				weapon4.SetTopLeft(-200, -200);
				weapon5.SetTopLeft(-200, -200);
			}
		}

		if (isDLA){
			playerB_pic_left.SetTopLeft(x, y);
			weapon.SetTopLeft(weaponX, weaponY);
			weapon2.SetTopLeft(weapon2X, weapon2Y);
			weapon3.SetTopLeft(weapon3X, weapon3Y);
			weapon4.SetTopLeft(weapon4X, weapon4Y);
			weapon5.SetTopLeft(weapon5X, weapon5Y);
			weaponX -= 8; weapon2X -= 10; weapon3X -= 13; weapon4X -= 9; weapon5X -= 8;
			weaponY += 2; weapon2Y += 1;  weapon4Y -= 1;  weapon5Y -= 2;

			if ((weapon3X < x - 230)){
				isDLA = false;
				weapon.SetTopLeft(-200, -200);
				weapon2.SetTopLeft(-200, -200);
				weapon3.SetTopLeft(-200, -200);
				weapon4.SetTopLeft(-200, -200);
				weapon5.SetTopLeft(-200, -200);
				weaponX = x; weapon2X = x; weapon3X = x; weapon4X = x; weapon5X = x;
				weaponY = y; weapon2Y = y; weapon3Y = y; weapon4Y = y; weapon5Y = y;
			}
		}

		if ((isAttack || weaponing == true) && !isDLA && !isDRA){
			if (weaponDir == 1){								//面向左邊
				//	attackB_L.SetTopLeft(x, y+135);			//(面向左邊)攻擊的圖片
				if (isAttack){
					weapon.SetTopLeft(x - 12, y + 135);   // x - 12 才有剛好出現在手上的感覺
					weaponX = x;
					weaponY = y + 135;

				}
				if (weaponing && weaponDir == 1){	//按了Attack之後即使立刻放手,飛刀依然要繼續飛一下
					weapon.SetTopLeft(weaponX - 12, weaponY);
					weaponX = weaponX - 12;

					//下面這行是判斷 到了一定距離之後使其開始往下掉 看上去有物理效果
					if (weaponX < playerB_pic_left.Left() - 150){
						weapon.SetTopLeft(weaponX - 12, weaponY + 3);
						weaponX = weaponX - 12;
						weaponY = weaponY + 3;
						//	Sleep(10);
					}

					//判斷射出一定距離之後將飛鏢位置設到視窗外，看起來會像消失
					if ((weaponX < playerB_pic_left.Left() - 230)){
						weapon.SetTopLeft(-200, -200);
						weaponing = false;
						weaponX = x; weaponY = y;
					}


				}
				playerB_pic_left.SetTopLeft(x, y + 135);
			}

			if (weaponDir == 2){ //面向右邊
				//	attackB_R.SetTopLeft(x, y + 135);			//(面向右邊)攻擊的圖片
				if (isAttack){
					weapon.SetTopLeft(x + 12, y + 145);  // x + 12 才有剛好出現在手上的感覺
					weaponX = x + 12;
					weaponY = y + 145;
				}
				if (weaponing&&weaponDir == 2){	//按了Attack之後即使立刻放手,飛刀依然要繼續飛一下
					weapon.SetTopLeft(weaponX + 12, weaponY);
					weaponX = weaponX + 12;

					//下面這行是判斷 到了一定距離之後使其開始往下掉 看上去有物理效果
					if (weaponX > playerB_pic_right.Left() + 150){
						weapon.SetTopLeft(weaponX + 12, weaponY + 3);
						weaponX = weaponX + 12;
						weaponY = weaponY + 3;
						//Sleep(10);
					}

					//判斷射出一定距離之後將飛鏢位置設到視窗外，看起來會像消失
					if (weaponX > playerB_pic_right.Left() + 230){
						weapon.SetTopLeft(-200, -200);
						weaponing = false;
						weaponX = x; weaponY = y;
					}
				}
				//playerB_pic_right.SetTopLeft(x, y + 135);
			} //for-> weaponDir==2

		}


		//}
		else if (!(isAttack || weaponing == true)) {
			weaponX = 2000;
			weaponY = 2000;
			missing = false;
		}

		if (missing){
			weaponX = 2000;
			weaponY = 2000;
			missing = false;
		}



		if (isAttack && dir == 1)	attackB_L.SetTopLeft(x, y + 135);
		if (isAttack && dir == 2)	attackB_R.SetTopLeft(x, y + 135);

		if (isJump && !isDLJ && !isDRJ){
			if (y < jumpY - 72){
				isJump = false;
				isLand = true;
			}
			jumpB_L.SetTopLeft(x, y + 135);
			jumpB_R.SetTopLeft(x, y + 135);
			y = y - 12;
		}
		if (isLand){
			if (y == jumpY)
				isLand = false;
			else{
				jumpB_L.SetTopLeft(x, y + 135);
				jumpB_R.SetTopLeft(x, y + 135);
				if (y < 350) y = y + 12;
				else isLand = false;
			}
		}

		if (isDefend){
			if (dir == 1)	defendB_L.SetTopLeft(x, y + 135);
			else			defendB_R.SetTopLeft(x, y + 135);
		}

		if (isRun){
			if (dir == 1){
				runB_L.SetTopLeft(x, y + 135);
				if (x >= 0)	x -= 8;
				runB_L.OnMove();				// 聽說要這樣才會換圖
				runB_L.OnMove();				// 覺得他跑太慢了應該多換幾次才對
				runB_L.OnMove();				// 覺得他跑太慢了應該多換幾次才對
				runB_L.OnMove();				// 覺得他跑太慢了應該多換幾次才對
			}
			else{
				runB_R.SetTopLeft(x, y + 135);
				if (x <= 700) x += 8;
				runB_R.OnMove();				//聽說要這樣才會換圖
				runB_R.OnMove();				// 覺得他跑太慢了應該多換幾次才對
				runB_R.OnMove();				// 覺得他跑太慢了應該多換幾次才對
				runB_R.OnMove();				// 覺得他跑太慢了應該多換幾次才對
			}
		}

		if (isDLJ){
			DLJ_Counter++;
			if (DLJ_Counter < 10){
				x -= 5; y -= 2;
			}
			if (DLJ_Counter >= 10 && DLJ_Counter < 30){
				x -= 6;
			}
			if (DLJ_Counter >= 30 && DLJ_Counter < 40){
				x -= 5; y += 2;
			}
			if (DLJ_Counter >= 40){
				DLJ_Counter = 0;
				isDLJ = false;
			}
			B_DLJ.SetTopLeft(x, y + 135);
			B_DLJ.OnMove();	B_DLJ.OnMove();	B_DLJ.OnMove();
		}
		if (isDRJ){
			DRJ_Counter++;
			if (DRJ_Counter < 10){
				x += 5; y -= 2;
			}
			if (DRJ_Counter >= 10 && DRJ_Counter < 30){
				x += 6;
			}
			if (DRJ_Counter >= 30 && DRJ_Counter < 40){
				x += 5; y += 2;
			}
			if (DRJ_Counter >= 40){
				DRJ_Counter = 0;
				isDRJ = false;
			}
			B_DRJ.SetTopLeft(x, y + 135);
			B_DRJ.OnMove();	B_DRJ.OnMove();	B_DRJ.OnMove();
		}

		playerB_pic_left.SetTopLeft(x, y + 135);
		playerB_pic_right.SetTopLeft(x, y + 135);
		playerB_pic_left.OnMove();
		playerB_pic_right.OnMove();

		//////////////////////////////此處處理技能//////////////////////////////////////
		if (isDefend)              //1.防
			counter1 = 0;



		if (counter1 < 35){
			counter1++;
			if (isMovingRight)    //2. 防右
				counter2 = 0;

			if (isMovingLeft)    //2. 防左
				counter3 = 0;

			if (isMovingDown)
				counter4 = 0;   //2.防下

		}

		if (counter2 + counter1 < 35){
			counter2++;
			if (isAttack && m2 > 2){           //防右攻!
				CAudio::Instance()->Play(AUDIO_dart);
				//這裡放上招式的設定
				m2 = m2 - 2;
				counter2 = 35;
				isDRA = true; isDLA = false; weaponing = false;
				weaponX = x + 30; weaponY = y + 10 + 135;
				weapon2X = x + 30; weapon2Y = y + 5 + 135;
				weapon3X = x + 30; weapon3Y = y + 135;
				weapon4X = x + 30; weapon4Y = y - 5 + 135;
				weapon5X = x + 30; weapon5Y = y - 10 + 135;
			}

			if (isJump && m2 > 10){           //防右跳!
				CAudio::Instance()->Play(AUDIO_blade);
				//這裡放上招式的設定
				m2 = m2 - 10;
				counter2 = 35;
				isDRJ = true; isDLJ = false; isJump = false;
			}

		}

		if (counter3 + counter1 < 35){
			counter3++;
			if (isAttack && m2 > 2){           //防左攻!
				CAudio::Instance()->Play(AUDIO_dart);
				//這裡放上招式的設定
				m2 = m2 - 2;
				counter3 = 35;
				isDLA = true; isDRA = false; weaponing = false;
				weaponX = x - 12; weaponY = y + 10 + 135;
				weapon2X = x - 12; weapon2Y = y + 5 + 135;
				weapon3X = x - 12; weapon3Y = y + 135;
				weapon4X = x - 12; weapon4Y = y - 5 + 135;
				weapon5X = x - 12; weapon5Y = y - 10 + 135;
			}

			if (isJump && m2 > 10){           //防左跳!
				CAudio::Instance()->Play(AUDIO_blade);
				//這裡放上招式的設定
				m2 = m2 - 10;
				counter3 = 35;
				isDRJ = false; isDLJ = true; isJump = false;
				originalY = y;
			}


		}

		if (counter4 + counter1 < 35){
			counter4++;
			if (isJump && m2 > 20){           //防下跳!
				CAudio::Instance()->Play(AUDIO_missing);
				//這裡放上招式的設定
				m2 = m2 - 20;
				counter4 = 35;
				hidden = true;
			}

		}

		if (hidden == true)	counter4++;
		if (counter4 > 180)	hidden = false;



		//////////////////////技能處理完畢///////////////////////////////

		// 自動回魔與自動回血
		if (!isMovingDown && !isMovingLeft && !isMovingRight && !isMovingUp && !isAttack && !weaponing && !isJump && !isLand){ //站著不動的狀況
			B_monaRecover++; B_bloodRecover++;
			if (B_monaRecover == 60){ //大約2秒
				if (m2 <= 66) m2 += 1;
				B_monaRecover = 0;
			}
			if (B_bloodRecover == 90){ //大約3秒
				if (b2 <= 66) b2 += 1;
				B_bloodRecover = 0;
			}
		}

	}  //for-> CPlayerB::OnMove()

	void CPlayerB::OnShow()
	{
		if (hidden){
			if (dir == 1){
				if (weaponing){
					CAudio::Instance()->Play(AUDIO_dart);
					weapon.OnMove();
					weapon.OnShow();
					if (isAttack) attackB_L.OnShow();
				}
				else if (isDLA){
					weapon.OnShow();  weapon2.OnShow(); weapon3.OnShow();
					weapon4.OnShow(); weapon5.OnShow(); playerB_pic_left.OnShow();
				}
				else if (isDLJ){
					B_DLJ.OnShow();
				}
			}

			if (dir == 2){
				if (weaponing){
					CAudio::Instance()->Play(AUDIO_dart);
					weapon.OnMove();
					weapon.OnShow();
					if (isAttack) attackB_R.OnShow();
				}
				else if (isDRA){
					weapon.OnShow();  weapon2.OnShow(); weapon3.OnShow();
					weapon4.OnShow(); weapon5.OnShow(); playerB_pic_right.OnShow();
				}
				else if (isDRJ){
					B_DRJ.OnShow();
				}
			}
		}



		if (!hidden){
			if (dir == 1){
				if (isAttack && !isDLA)
					attackB_L.OnShow();
				else if (weaponing && !isDLA && !hasTool){
					CAudio::Instance()->Play(AUDIO_dart);
					weapon.OnMove(); weapon.OnShow(); if (!isAttack) playerB_pic_left.OnShow();
				}
				else if (weaponing && hasTool)	{
					CAudio::Instance()->Play(AUDIO_dart);
					playerB_pic_left.OnShow();
				}
				else if ((isJump || isLand) && !isDLJ){
					CAudio::Instance()->Play(AUDIO_jump);
					jumpB_L.OnShow();
					Sleep(40);
				}
				else if (isDefend){
					defendB_L.OnShow();
				}
				else if (isRun){
					CAudio::Instance()->Play(AUDIO_run);
					runB_L.OnShow();
				}
				else if (isMovingLeft){
					playerB_walkL.OnShow();
				}
				else if (isDLA){
					weapon.OnShow();  weapon2.OnShow(); weapon3.OnShow();
					weapon4.OnShow(); weapon5.OnShow(); playerB_pic_left.OnShow();
				}
				else if (isDLJ){
					B_DLJ.OnShow();
				}
				else
					playerB_pic_left.OnShow();
			}

			else if (dir == 2){
				if (isAttack && !isDRA)
					attackB_R.OnShow();
				else if (weaponing && !isDRA && !hasTool){
					CAudio::Instance()->Play(AUDIO_dart);
					weapon.OnMove(); weapon.OnShow(); if (!isAttack) playerB_pic_right.OnShow();
				}
				else if (weaponing && hasTool)	{
					CAudio::Instance()->Play(AUDIO_dart);
					playerB_pic_right.OnShow();
				}
				else if ((isJump || isLand) && !isDRJ){
					CAudio::Instance()->Play(AUDIO_jump);
					jumpB_R.OnShow();
					Sleep(40);
				}
				else if (isDefend){
					defendB_R.OnShow();
				}
				else if (isRun){
					CAudio::Instance()->Play(AUDIO_run);
					runB_R.OnShow();
				}
				else if (isMovingRight){
					playerB_walkR.OnShow();
				}
				else if (isDRA){
					weapon.OnShow();  weapon2.OnShow(); weapon3.OnShow();
					weapon4.OnShow(); weapon5.OnShow(); playerB_pic_right.OnShow();
				}
				else if (isDRJ){
					B_DRJ.OnShow();
				}
				else
					playerB_pic_right.OnShow();
			}
		}
	}

	//////////////////////////////// 你好我是道具 ////////////////////////////////

	CTool::CTool(){
		Initialize();
	}

	void CTool::Initialize(){

		toolAmount = 3;

		toolNumber1 = toolNumber2 = toolNumber3 = 0;

		// toolKind= 1 迴力鏢 2 石頭 3 箱子 4 棒球 5 短刀 6 回魔藥水 7 鋤頭 8 回血藥水
		toolKind();
		tool1X = tool1Y = tool2X = tool2Y = tool3X = tool3Y = 0;
		y1 = y2 = y3 = 0;
		tool1takenByA = tool1takenByB = tool2takenByA = tool2takenByB =
			tool3takenByA = tool3takenByB = visible = isAttack = false;

	}

	void CTool::_toolKind(int num){

	}

	void CTool::toolKind(){

		if (toolAmount >= 1)	toolNumber1 = 1;
		if (toolAmount >= 2)	toolNumber2 = 5;	// 短刀
		if (toolAmount >= 3){
			for (;;){
				toolNumber3 = (rand() % 8) + 1;
				if (toolNumber3 != 1 && toolNumber3 != 5)	break;
			}
		}
	}

	void CTool::LoadBitmap(){
		if (toolNumber1 == 1)		tool1.AddBitmap(IDB_toolKind_1, RGB(255, 255, 255));
		if (toolNumber1 == 2)		tool1.AddBitmap(IDB_toolKind_2, RGB(255, 255, 255));
		if (toolNumber1 == 3)		tool1.AddBitmap(IDB_toolKind_3, RGB(255, 255, 255));
		if (toolNumber1 == 4)		tool1.AddBitmap(IDB_toolKind_4, RGB(255, 255, 255));
		if (toolNumber1 == 5)		tool1.AddBitmap(IDB_toolKind_5, RGB(255, 255, 255));
		if (toolNumber1 == 6)		tool1.AddBitmap(IDB_toolKind_6, RGB(255, 255, 255));
		if (toolNumber1 == 7)		tool1.AddBitmap(IDB_toolKind_7, RGB(255, 255, 255));
		if (toolNumber1 == 8)		tool1.AddBitmap(IDB_toolKind_8, RGB(255, 255, 255));

		if (toolNumber2 == 1)		tool2.AddBitmap(IDB_toolKind_1, RGB(255, 255, 255));
		if (toolNumber2 == 2)		tool2.AddBitmap(IDB_toolKind_2, RGB(255, 255, 255));
		if (toolNumber2 == 3)		tool2.AddBitmap(IDB_toolKind_3, RGB(255, 255, 255));
		if (toolNumber2 == 4)		tool2.AddBitmap(IDB_toolKind_4, RGB(255, 255, 255));
		if (toolNumber2 == 5)		tool2.AddBitmap(IDB_toolKind_5, RGB(255, 255, 255));
		if (toolNumber2 == 6)		tool2.AddBitmap(IDB_toolKind_6, RGB(255, 255, 255));
		if (toolNumber2 == 7)		tool2.AddBitmap(IDB_toolKind_7, RGB(255, 255, 255));
		if (toolNumber2 == 8)		tool2.AddBitmap(IDB_toolKind_8, RGB(255, 255, 255));

		if (toolNumber3 == 1)		tool3.AddBitmap(IDB_toolKind_1, RGB(255, 255, 255));
		if (toolNumber3 == 2)		tool3.AddBitmap(IDB_toolKind_2, RGB(255, 255, 255));
		if (toolNumber3 == 3)		tool3.AddBitmap(IDB_toolKind_3, RGB(255, 255, 255));
		if (toolNumber3 == 4)		tool3.AddBitmap(IDB_toolKind_4, RGB(255, 255, 255));
		if (toolNumber3 == 5)		tool3.AddBitmap(IDB_toolKind_5, RGB(255, 255, 255));
		if (toolNumber3 == 6)		tool3.AddBitmap(IDB_toolKind_6, RGB(255, 255, 255));
		if (toolNumber3 == 7)		tool3.AddBitmap(IDB_toolKind_7, RGB(255, 255, 255));
		if (toolNumber3 == 8)		tool3.AddBitmap(IDB_toolKind_8, RGB(255, 255, 255));
	}

	void CTool::GetPlayerA_X(int X){
		A_X = X;
	}

	void CTool::GetPlayerB_X(int X){
		B_X = X;
	}
	void CTool::GetPlayerA_Y(int Y){
		A_Y = Y;
	}
	void CTool::GetPlayerB_Y(int Y){
		B_Y = Y;
	}
	int CTool::GetToolAmount(){
		return toolAmount;
	}

	void CTool::SetShow(bool _visible, int _time1){
		visible = _visible;
		isFirstTool = _time1;
	}

	bool CTool::GetVisible(){
		return visible;
	}

	void CTool::SetTool1XY(int x, int y) {
		tool1X = x, tool1Y = y;
	}
	int CTool::GetTool1X(){
		return tool1X;
	}
	int CTool::GetTool1Y(){
		return tool1Y;
	}

	void CTool::SetTool2XY(int x, int y){
		tool2X = x, tool2Y = y;
	}
	int CTool::GetTool2X(){
		return tool2X;
	}
	int CTool::GetTool2Y(){
		return tool2Y;
	}

	void CTool::SetTool3XY(int x, int y){
		tool3X = x, tool3Y = y;
	}
	int CTool::GetTool3X(){
		return tool3X;
	}
	int CTool::GetTool3Y(){
		return tool3Y;
	}

	void CTool::A_Take1(bool isTake){
		tool1takenByA = isTake;
	}
	void CTool::A_Take2(bool isTake){
		tool2takenByA = isTake;
	}
	void CTool::A_Take3(bool isTake){
		tool3takenByA = isTake;
	}
	void CTool::B_Take1(bool isTake){
		tool1takenByB = isTake;
	}
	void CTool::B_Take2(bool isTake){
		tool2takenByB = isTake;
	}
	void CTool::B_Take3(bool isTake){
		tool3takenByB = isTake;
	}
	bool CTool::Whether_A_Take1(){
		return tool1takenByA;
	}
	bool CTool::Whether_A_Take2(){
		return tool2takenByA;
	}
	bool CTool::Whether_A_Take3(){
		return tool3takenByA;
	}
	bool CTool::Whether_B_Take1(){
		return tool1takenByB;
	}
	bool CTool::Whether_B_Take2(){
		return tool2takenByB;
	}
	bool CTool::Whether_B_Take3(){
		return tool3takenByB;
	}

	int CTool::GetTool1Number(){
		return toolNumber1;
	}

	int CTool::GetTool2Number(){
		return toolNumber2;
	}

	int CTool::GetTool3Number(){
		return toolNumber3;
	}

	void CTool::SetToolAttack(bool flag, int _toolNumber){

	}

	void CTool::SetIsFirstTool(int i){
		isFirstTool = i;
	}

	void CTool::OnMove(){
		int _tool1X, _tool1Y, _tool2X, _tool2Y, _tool3X, _tool3Y;
		int temp = -1;
		if (B_X < A_X){
			temp = B_X;
			B_X = A_X;
			A_X = temp;
		}
		_tool1X = (rand() % ((A_X + B_X) / 2 + 200)); // 也就是 當AX=300,BX=360時，亂數範圍在 (300+360)/2+200=0~530間
		_tool1Y = (rand() % 230) + 320; // Y值在320~550間
		_tool2X = (rand() % ((A_X + B_X) / 2 + 200));
		_tool2Y = (rand() % 230) + 320;
		_tool3X = (rand() % ((A_X + B_X) / 2 + 200));
		_tool3Y = (rand() % 230) + 320;

		if (tool1X == 0)	tool1X = _tool1X;
		if (tool1Y == 0)	tool1Y = _tool1Y;
		if (tool2X == 0)	tool2X = _tool2X;
		if (tool2Y == 0)	tool2Y = _tool2Y;
		if (tool3X == 0)	tool3X = _tool3X;
		if (tool3Y == 0)	tool3Y = _tool3Y;

		if (temp != -1){
			temp = B_X;
			B_X = A_X;
			A_X = temp;
		}

		if (visible){

			if (toolAmount >= 1 && y1 < tool1Y)	tool1.SetTopLeft(tool1X, y1);
			else if (!tool1takenByA && !tool1takenByB &&toolAmount >= 1 && y1 >= tool1Y)	tool1.SetTopLeft(tool1X, tool1Y);
			if (toolAmount >= 2 && y2 < tool2Y)	tool2.SetTopLeft(tool2X, y2);
			else if (!tool2takenByA && !tool2takenByB &&toolAmount >= 2 && y2 >= tool2Y)	tool2.SetTopLeft(tool2X, tool2Y);
			if (toolAmount >= 3 && y3 < tool3Y)	tool3.SetTopLeft(tool3X, y3);
			else if (!tool3takenByA && !tool3takenByB &&toolAmount >= 3 && y3 >= tool3Y)	tool3.SetTopLeft(tool3X, tool3Y);

			if (tool1takenByA && toolNumber1 == 1)
				tool1.SetTopLeft(A_X - 15, A_Y + 175); // -15看起來比較像拿在左手
			if (tool1takenByB && toolNumber1 == 1)
				tool1.SetTopLeft(B_X - 15, B_Y + 175);

			if (tool2takenByA && toolNumber2 == 5)
				tool2.SetTopLeft(A_X - 15, A_Y + 175); // -15看起來比較像拿在左手
			if (tool2takenByB && toolNumber2 == 5)
				tool2.SetTopLeft(B_X - 15, B_Y + 175);

			y1 += 10; y2 += 10; y3 += 10;

		}
	}

	void CTool::OnShow(){
		if (visible){
			if (toolAmount >= 1)	tool1.OnShow();
			if (toolAmount >= 2)	tool2.OnShow();
			if (toolAmount >= 3)	tool3.OnShow();
		}
	}

	////////////////////// 你好我是只有裝飾作用的道具 //////////////////////

	CTool_HAHA::CTool_HAHA(){
		Initialize();
	}

	void CTool_HAHA::Initialize(){

		toolAmount = 3;

		toolNumber1 = toolNumber2 = toolNumber3 = 0;

		// toolKind= 1 迴力鏢 2 石頭 3 箱子 4 棒球 5 短刀 6 回魔藥水 7 鋤頭 8 回血藥水
		toolKind();
		tool1X = tool1Y = tool2X = tool2Y = tool3X = tool3Y = 0;
		y1 = y2 = y3 = 0;
		tool1takenByA = tool1takenByB = tool2takenByA = tool2takenByB =
			tool3takenByA = tool3takenByB = visible = false;

	}


	void CTool_HAHA::toolKind(){

		if (toolAmount >= 1) 	toolNumber1 = ((rand() % 6) + 1);
		if (toolAmount >= 2)	toolNumber2 = ((rand() % 6) + 1);

		if (toolAmount >= 3)	toolNumber3 = ((rand() % 6) + 1);
	}

	void CTool_HAHA::LoadBitmap(){
		if (toolNumber1 == 1)		tool1.AddBitmap(IDB_toolKind_8, RGB(255, 255, 255));
		if (toolNumber1 == 2)		tool1.AddBitmap(IDB_toolKind_2, RGB(255, 255, 255));
		if (toolNumber1 == 3)		tool1.AddBitmap(IDB_toolKind_3, RGB(255, 255, 255));
		if (toolNumber1 == 4)		tool1.AddBitmap(IDB_toolKind_4, RGB(255, 255, 255));
		if (toolNumber1 == 5)		tool1.AddBitmap(IDB_toolKind_7, RGB(255, 255, 255));
		if (toolNumber1 == 6)		tool1.AddBitmap(IDB_toolKind_6, RGB(255, 255, 255));


		if (toolNumber2 == 1)		tool2.AddBitmap(IDB_toolKind_8, RGB(255, 255, 255));
		if (toolNumber2 == 2)		tool2.AddBitmap(IDB_toolKind_2, RGB(255, 255, 255));
		if (toolNumber2 == 3)		tool2.AddBitmap(IDB_toolKind_3, RGB(255, 255, 255));
		if (toolNumber2 == 4)		tool2.AddBitmap(IDB_toolKind_4, RGB(255, 255, 255));
		if (toolNumber2 == 5)		tool2.AddBitmap(IDB_toolKind_7, RGB(255, 255, 255));
		if (toolNumber2 == 6)		tool2.AddBitmap(IDB_toolKind_6, RGB(255, 255, 255));

		if (toolNumber3 == 1)		tool3.AddBitmap(IDB_toolKind_8, RGB(255, 255, 255));
		if (toolNumber3 == 2)		tool3.AddBitmap(IDB_toolKind_2, RGB(255, 255, 255));
		if (toolNumber3 == 3)		tool3.AddBitmap(IDB_toolKind_3, RGB(255, 255, 255));
		if (toolNumber3 == 4)		tool3.AddBitmap(IDB_toolKind_4, RGB(255, 255, 255));
		if (toolNumber3 == 5)		tool3.AddBitmap(IDB_toolKind_7, RGB(255, 255, 255));
		if (toolNumber3 == 6)		tool3.AddBitmap(IDB_toolKind_6, RGB(255, 255, 255));
	}

	void CTool_HAHA::GetPlayerA_X(int X){
		A_X = X;
	}

	void CTool_HAHA::GetPlayerB_X(int X){
		B_X = X;
	}
	void CTool_HAHA::GetPlayerA_Y(int Y){
		A_Y = Y;
	}
	void CTool_HAHA::GetPlayerB_Y(int Y){
		B_Y = Y;
	}
	int CTool_HAHA::GetToolAmount(){
		return toolAmount;
	}

	void CTool_HAHA::SetShow(bool _visible, int _time1){
		visible = _visible;
		isFirstTool = _time1;
	}

	bool CTool_HAHA::GetVisible(){
		return visible;
	}

	void CTool_HAHA::SetTool1XY(int x, int y) {
		tool1X = x, tool1Y = y;
	}
	int CTool_HAHA::GetTool1X(){
		return tool1X;
	}
	int CTool_HAHA::GetTool1Y(){
		return tool1Y;
	}

	void CTool_HAHA::SetTool2XY(int x, int y){
		tool2X = x, tool2Y = y;
	}
	int CTool_HAHA::GetTool2X(){
		return tool2X;
	}
	int CTool_HAHA::GetTool2Y(){
		return tool2Y;
	}

	void CTool_HAHA::SetTool3XY(int x, int y){
		tool3X = x, tool3Y = y;
	}
	int CTool_HAHA::GetTool3X(){
		return tool3X;
	}
	int CTool_HAHA::GetTool3Y(){
		return tool3Y;
	}


	int CTool_HAHA::GetTool1Number(){
		return toolNumber1;
	}

	int CTool_HAHA::GetTool2Number(){
		return toolNumber2;
	}

	int CTool_HAHA::GetTool3Number(){
		return toolNumber3;
	}

	void CTool_HAHA::SetIsFirstTool(int i){
		isFirstTool = i;
	}

	void CTool_HAHA::OnMove(){
		int _tool1X, _tool1Y, _tool2X, _tool2Y, _tool3X, _tool3Y;
		int temp = -1;
		if (B_X < A_X){
			temp = B_X;
			B_X = A_X;
			A_X = temp;
		}
		_tool1X = (rand() % ((A_X + B_X) / 2 + 200)); // 也就是 當AX=300,BX=360時，亂數範圍在 (300+360)/2+200=0~530間
		_tool1Y = (rand() % 230) + 320; // Y值在320~550間
		_tool2X = (rand() % ((A_X + B_X) / 2 + 200));
		_tool2Y = (rand() % 230) + 320;
		_tool3X = (rand() % ((A_X + B_X) / 2 + 200));
		_tool3Y = (rand() % 230) + 320;

		if (tool1X == 0)	tool1X = _tool1X;
		if (tool1Y == 0)	tool1Y = _tool1Y;
		if (tool2X == 0)	tool2X = _tool2X;
		if (tool2Y == 0)	tool2Y = _tool2Y;
		if (tool3X == 0)	tool3X = _tool3X;
		if (tool3Y == 0)	tool3Y = _tool3Y;

		if (temp != -1){
			temp = B_X;
			B_X = A_X;
			A_X = temp;
		}

		if (visible){

			if (toolAmount >= 1 && y1 < tool1Y)	tool1.SetTopLeft(tool1X, y1);
			else if (!tool1takenByA && !tool1takenByB &&toolAmount >= 1 && y1 >= tool1Y)	tool1.SetTopLeft(tool1X, tool1Y);
			if (toolAmount >= 2 && y2 < tool2Y)	tool2.SetTopLeft(tool2X, y2);
			else if (!tool2takenByA && !tool2takenByB &&toolAmount >= 2 && y2 >= tool2Y)	tool2.SetTopLeft(tool2X, tool2Y);
			if (toolAmount >= 3 && y3 < tool3Y)	tool3.SetTopLeft(tool3X, y3);
			else if (!tool3takenByA && !tool3takenByB &&toolAmount >= 3 && y3 >= tool3Y)	tool3.SetTopLeft(tool3X, tool3Y);

			if (tool1takenByA && toolNumber1 == 1)
				tool1.SetTopLeft(A_X - 15, A_Y + 175); // -15看起來比較像拿在左手
			if (tool1takenByB && toolNumber1 == 1)
				tool1.SetTopLeft(B_X - 15, B_Y + 175);

			if (tool2takenByA && toolNumber2 == 5)
				tool2.SetTopLeft(A_X - 15, A_Y + 175); // -15看起來比較像拿在左手
			if (tool2takenByB && toolNumber2 == 5)
				tool2.SetTopLeft(B_X - 15, B_Y + 175);

			y1 += 10; y2 += 10; y3 += 10;

		}
	}

	void CTool_HAHA::OnShow(){
		if (visible){
			if (toolAmount >= 1)	tool1.OnShow();
			if (toolAmount >= 2)	tool2.OnShow();
			if (toolAmount >= 3)	tool3.OnShow();
		}
	}


	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	/////////////////////////////////////////////////////////////////////////////

	CGameStateInit::CGameStateInit(CGame* g)
		: CGameState(g)
	{
	}

	void CGameStateInit::OnInit()
	{
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(0);	// 一開始的loading進度為0%
		//
		// 開始載入資料
		//
		logo.LoadBitmap(IDB_back);
		logo_choose.LoadBitmap(IDB_start_button);
		introduce.LoadBitmap(IDB_introduce);

		isClick = toIntroduce = false;

		Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
		//
		srand((unsigned)time(NULL));

	}

	void CGameStateInit::OnBeginState()
	{
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_SPACE = ' ';
		const char KEY_INTRODUCE = 0x70;	// F1說明
		if (nChar == KEY_SPACE)
			GotoGameState(GAME_STATE_RUN);						// 切換至GAME_STATE_RUN
		if (nChar == KEY_INTRODUCE)
		{
			if (toIntroduce) toIntroduce = false;
			else			 toIntroduce = true;
		}
		else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		if ((point.x >= 320 && point.x <= 670)
			&& (point.y >= (225 + 60) && point.y <= (265 + 60))){
			isClick = true;
			GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
		}
		else isClick = false;
	}

	void CGameStateInit::OnMouseMove(UINT nFlags, CPoint point){
		if ((point.x >= 320 && point.x <= 670)
			&& (point.y >= (225 + 60) && point.y <= (265 + 60))){
			isClick = true;
		}
		else isClick = false;
	}


	void CGameStateInit::OnShow()
	{
		//
		// 貼上logo
		//
		logo.SetTopLeft((SIZE_X - logo.Width()) / 2, (SIZE_Y - logo.Height()) / 2);

		logo_choose.SetTopLeft((SIZE_X - logo.Width()) / 2, (SIZE_Y - logo.Height()) / 2);

		introduce.SetTopLeft((SIZE_X - logo.Width()) / 2, (SIZE_Y - logo.Height()) / 2);

		if (isClick == false)	logo.ShowBitmap();
		else				logo_choose.ShowBitmap();

		if (toIntroduce)	introduce.ShowBitmap();
		//
		// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
		//
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
		CFont f, *fp;
		f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(16, 32, 108));
		pDC->SetTextColor(RGB(255, 255, 255));
		//pDC->TextOut(120, 220, "123456789");
		if (!toIntroduce)	pDC->TextOut(600, 100, "F1 顯示說明圖");
		//if (ENABLE_GAME_PAUSE)
		//	pDC->TextOut(5, 425, "Press Ctrl-Q to pause the Game.");
		////	pDC->TextOut(5, 455, "Press Alt-F4 or ESC to Quit.");
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	}

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	/////////////////////////////////////////////////////////////////////////////

	CGameStateOver::CGameStateOver(CGame* g)
		: CGameState(g)
	{
	}

	void CGameStateOver::OnMove()
	{
		counter--;
		if (counter < 0)
			GotoGameState(GAME_STATE_INIT);
	}

	void CGameStateOver::OnBeginState()
	{
		counter = 30 * 5; // 5 seconds
	}

	void CGameStateOver::OnInit()
	{
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
		//
		// 開始載入資料
		//
		Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 最終進度為100%
		//
		ShowInitProgress(100);
	}

	void CGameStateOver::OnShow()
	{
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
		CFont f, *fp;
		f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));
		char str[80];								// Demo 數字對字串的轉換
		sprintf(str, "Game Over ! (%d)", counter / 30);
		pDC->TextOut(240, 210, str);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	}

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	/////////////////////////////////////////////////////////////////////////////

	CGameStateRun::CGameStateRun(CGame* g)
		: CGameState(g), NUMBALLS(28)
	{
		ball = new CBall[NUMBALLS];
	}

	CGameStateRun::~CGameStateRun()
	{
		delete[] ball;
	}

	void CGameStateRun::OnBeginState()
	{

		const int BALL_GAP = 90;
		const int BALL_XY_OFFSET = 45;
		const int BALL_PER_ROW = 7;
		const int HITS_LEFT = 10;
		const int HITS_LEFT_X = 590;
		const int HITS_LEFT_Y = 0;
		const int BACKGROUND_X = 0;
		const int ANIMATION_SPEED = 15;
		for (int i = 0; i < NUMBALLS; i++)  				// 設定球的起始座標
		{
			int y_pos = i / BALL_PER_ROW;
			//	ball[i].SetXY(x_pos * BALL_GAP + BALL_XY_OFFSET, y_pos * BALL_GAP + BALL_XY_OFFSET);
			//	ball[i].SetDelay(x_pos);
			ball[i].SetIsAlive(true);
		}
		eraser.Initialize();
		background.SetTopLeft(-250, 135);				// 設定背景的起始座標
		help.SetTopLeft(0, SIZE_Y - help.Height());			// 設定說明圖的起始座標
		hits_left.SetInteger(HITS_LEFT);					// 指定剩下的撞擊數
		hits_left.SetTopLeft(HITS_LEFT_X, HITS_LEFT_Y);		// 指定剩下撞擊數的座標
		//CAudio::Instance()->Play(AUDIO_LAKE, true);			// 撥放 WAVE
		//CAudio::Instance()->Play(AUDIO_DING, false);		// 撥放 WAVE
		//CAudio::Instance()->Play(AUDIO_NTUT, true);			// 撥放 MIDI


		 CAudio::Instance()->Play(AUDIO_stage1, true);

		playerA_logo.SetTopLeft(305, 40);
		playerB_logo.SetTopLeft(440, 40);


		playerA.Initialize();
		playerA_2.Initialize();
		playerB.Initialize();
		playerB_2.Initialize();

		tool1A.Initialize();

		///// 以下道具開放裝飾 //////
		tool1B.Initialize();
		tool1C.Initialize();
		tool2A.Initialize();
		tool2B.Initialize();
		tool2C.Initialize();
		tool3A.Initialize();
		tool3B.Initialize();
		tool3C.Initialize();
	}

	void CGameStateRun::OnMove()							// 移動遊戲元素
	{
		//
		// 如果希望修改cursor的樣式，則將下面程式的commment取消即可
		//
		// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
		//
		// 移動背景圖的座標
		//
		/*	if (background.Top() > SIZE_Y)
		background.SetTopLeft(60, -background.Height());
		background.SetTopLeft(background.Left(), background.Top() + 1);
		*/	//
		// 移動球
		//



		////////////// 邊界設定 跑步的地方還有小bug //////////////
		if (((playerA.GetX1() > 700 && playerB.GetX1() > 200) || (playerB.GetX1() > 700 && playerA.GetX1() > 200))
			&& (background.Left() > -800)){
			background.SetTopLeft(background.Left() - 4, 135);
			if (!playerB.WhetherMoving() && !playerB.WhetherRuning())
				playerB.SetXY(playerB.GetX1() - 4, playerB.GetY1());
			if (!playerA.WhetherMoving() && !playerA.WhetherRuning())
				playerA.SetXY(playerA.GetX1() - 4, playerA.GetY1());
			if (!tool1A.Whether_A_Take1() && !tool1A.Whether_B_Take1())
				tool1A.SetTool1XY(tool1A.GetTool1X() - 4, tool1A.GetTool1Y());
			if (!tool1A.Whether_A_Take2() && !tool1A.Whether_B_Take2())
				tool1A.SetTool2XY(tool1A.GetTool2X() - 4, tool1A.GetTool2Y());
			if (!tool1A.Whether_A_Take3() && !tool1A.Whether_B_Take3())
				tool1A.SetTool3XY(tool1A.GetTool3X() - 4, tool1A.GetTool3Y());


			///// 裝飾用道具 /////
			tool1B.SetTool1XY(tool1B.GetTool1X() - 4, tool1B.GetTool1Y());
			tool1B.SetTool2XY(tool1B.GetTool2X() - 4, tool1B.GetTool2Y());
			tool1B.SetTool3XY(tool1B.GetTool3X() - 4, tool1B.GetTool3Y());
			tool1C.SetTool1XY(tool1C.GetTool1X() - 4, tool1C.GetTool1Y());
			tool1C.SetTool2XY(tool1C.GetTool2X() - 4, tool1C.GetTool2Y());
			tool1C.SetTool3XY(tool1C.GetTool3X() - 4, tool1C.GetTool3Y());

			tool2A.SetTool1XY(tool2A.GetTool1X() - 4, tool2A.GetTool1Y());
			tool2A.SetTool2XY(tool2A.GetTool2X() - 4, tool2A.GetTool2Y());
			tool2A.SetTool3XY(tool2A.GetTool3X() - 4, tool2A.GetTool3Y());
			tool2B.SetTool1XY(tool2B.GetTool1X() - 4, tool2B.GetTool1Y());
			tool2B.SetTool2XY(tool2B.GetTool2X() - 4, tool2B.GetTool2Y());
			tool2B.SetTool3XY(tool2B.GetTool3X() - 4, tool2B.GetTool3Y());
			tool2C.SetTool1XY(tool2C.GetTool1X() - 4, tool2C.GetTool1Y());
			tool2C.SetTool2XY(tool2C.GetTool2X() - 4, tool2C.GetTool2Y());
			tool2C.SetTool3XY(tool2C.GetTool3X() - 4, tool2C.GetTool3Y());

			tool3A.SetTool1XY(tool3A.GetTool1X() - 4, tool3A.GetTool1Y());
			tool3A.SetTool2XY(tool3A.GetTool2X() - 4, tool3A.GetTool2Y());
			tool3A.SetTool3XY(tool3A.GetTool3X() - 4, tool3A.GetTool3Y());
			tool3B.SetTool1XY(tool3B.GetTool1X() - 4, tool3B.GetTool1Y());
			tool3B.SetTool2XY(tool3B.GetTool2X() - 4, tool3B.GetTool2Y());
			tool3B.SetTool3XY(tool3B.GetTool3X() - 4, tool3B.GetTool3Y());
			tool3C.SetTool1XY(tool3C.GetTool1X() - 4, tool3C.GetTool1Y());
			tool3C.SetTool2XY(tool3C.GetTool2X() - 4, tool3C.GetTool2Y());
			tool3C.SetTool3XY(tool3C.GetTool3X() - 4, tool3C.GetTool3Y());

		}

		if (((playerA.GetX1() < 100 && playerB.GetX1() < 500) || (playerB.GetX1() < 100 && playerA.GetX1() < 500))
			&& (background.Left() < 0)){
			background.SetTopLeft(background.Left() + 4, 135);
			if (!playerB.WhetherMoving() && !playerB.WhetherRuning())
				playerB.SetXY(playerB.GetX1() + 4, playerB.GetY1());
			if (!playerA.WhetherMoving() && !playerA.WhetherRuning())
				playerA.SetXY(playerA.GetX1() + 4, playerA.GetY1());
			if (!tool1A.Whether_A_Take1() && !tool1A.Whether_B_Take1())
				tool1A.SetTool1XY(tool1A.GetTool1X() + 4, tool1A.GetTool1Y());
			if (!tool1A.Whether_A_Take2() && !tool1A.Whether_B_Take2())
				tool1A.SetTool2XY(tool1A.GetTool2X() + 4, tool1A.GetTool2Y());
			if (!tool1A.Whether_A_Take3() && !tool1A.Whether_B_Take3())
				tool1A.SetTool3XY(tool1A.GetTool3X() + 4, tool1A.GetTool3Y());

			///// 裝飾用道具 /////
			tool1B.SetTool1XY(tool1B.GetTool1X() + 4, tool1B.GetTool1Y());
			tool1B.SetTool2XY(tool1B.GetTool2X() + 4, tool1B.GetTool2Y());
			tool1B.SetTool3XY(tool1B.GetTool3X() + 4, tool1B.GetTool3Y());
			tool1C.SetTool1XY(tool1C.GetTool1X() + 4, tool1C.GetTool1Y());
			tool1C.SetTool2XY(tool1C.GetTool2X() + 4, tool1C.GetTool2Y());
			tool1C.SetTool3XY(tool1C.GetTool3X() + 4, tool1C.GetTool3Y());

			tool2A.SetTool1XY(tool2A.GetTool1X() + 4, tool2A.GetTool1Y());
			tool2A.SetTool2XY(tool2A.GetTool2X() + 4, tool2A.GetTool2Y());
			tool2A.SetTool3XY(tool2A.GetTool3X() + 4, tool2A.GetTool3Y());
			tool2B.SetTool1XY(tool2B.GetTool1X() + 4, tool2B.GetTool1Y());
			tool2B.SetTool2XY(tool2B.GetTool2X() + 4, tool2B.GetTool2Y());
			tool2B.SetTool3XY(tool2B.GetTool3X() + 4, tool2B.GetTool3Y());
			tool2C.SetTool1XY(tool2C.GetTool1X() + 4, tool2C.GetTool1Y());
			tool2C.SetTool2XY(tool2C.GetTool2X() + 4, tool2C.GetTool2Y());
			tool2C.SetTool3XY(tool2C.GetTool3X() + 4, tool2C.GetTool3Y());

			tool3A.SetTool1XY(tool3A.GetTool1X() + 4, tool3A.GetTool1Y());
			tool3A.SetTool2XY(tool3A.GetTool2X() + 4, tool3A.GetTool2Y());
			tool3A.SetTool3XY(tool3A.GetTool3X() + 4, tool3A.GetTool3Y());
			tool3B.SetTool1XY(tool3B.GetTool1X() + 4, tool3B.GetTool1Y());
			tool3B.SetTool2XY(tool3B.GetTool2X() + 4, tool3B.GetTool2Y());
			tool3B.SetTool3XY(tool3B.GetTool3X() + 4, tool3B.GetTool3Y());
			tool3C.SetTool1XY(tool3C.GetTool1X() + 4, tool3C.GetTool1Y());
			tool3C.SetTool2XY(tool3C.GetTool2X() + 4, tool3C.GetTool2Y());
			tool3C.SetTool3XY(tool3C.GetTool3X() + 4, tool3C.GetTool3Y());

		}

		//////////////// A的普通攻擊 B扣血設定////////////////
		if (playerA.GetWeaponY() - ((playerB.GetY1() + playerB.GetY2()) / 2) > -5 &&
			playerA.GetWeaponY() - ((playerB.GetY1() + playerB.GetY2()) / 2) < 55 &&

			playerA.GetWeaponX() - ((playerB.GetX1() + playerB.GetX2()) / 2) > -10 &&
			playerA.GetWeaponX() - ((playerB.GetX1() + playerB.GetX2()) / 2) < 5)
			playerB.Setb2(-1);

		//// A防前跳 B扣血設定 ////
		if ((playerA.GetWeaponBallY() - playerB.GetY2() > 1 ||
			playerB.GetY1() - (playerA.GetWeaponBallY() + 59) > 1) &&

			playerA.GetWeaponBallX() - ((playerB.GetX1() + playerB.GetX2()) / 2) > -20 &&
			playerA.GetWeaponBallX() - ((playerB.GetX1() + playerB.GetX2()) / 2) < 20)
			playerB.Setb2(-2);

		//// A防前攻 B扣血設定 ////

		if (playerA.Getweapon_Continue1Y() - (playerB.GetY2() + playerB.GetY1()) / 2 > 70 &&
			playerA.Getweapon_Continue1Y() - (playerB.GetY2() + playerB.GetY1()) / 2 < 140 &&
			playerA.Getweapon_Continue1X() - ((playerB.GetX1() + playerB.GetX2()) / 2) > -10 &&
			playerA.Getweapon_Continue1X() - ((playerB.GetX1() + playerB.GetX2()) / 2) < 5)
			playerB.Setb2(-2);


		if (playerA.Getweapon_Continue2Y() - (playerB.GetY2() + playerB.GetY1()) / 2 > 70 &&
			playerA.Getweapon_Continue2Y() - (playerB.GetY2() + playerB.GetY1()) / 2 < 140 &&
			playerA.Getweapon_Continue2X() - ((playerB.GetX1() + playerB.GetX2()) / 2) > -10 &&
			playerA.Getweapon_Continue2X() - ((playerB.GetX1() + playerB.GetX2()) / 2) < 5)
			playerB.Setb2(-2);

		if (playerA.Getweapon_Continue3Y() - (playerB.GetY2() + playerB.GetY1()) / 2 > 70 &&
			playerA.Getweapon_Continue3Y() - (playerB.GetY2() + playerB.GetY1()) / 2 < 140 &&
			playerA.Getweapon_Continue3X() - ((playerB.GetX1() + playerB.GetX2()) / 2) > -10 &&
			playerA.Getweapon_Continue3X() - ((playerB.GetX1() + playerB.GetX2()) / 2) < 5)
			playerB.Setb2(-2);

		if (playerA.Getweapon_Continue4Y() - (playerB.GetY2() + playerB.GetY1()) / 2 > 70 &&
			playerA.Getweapon_Continue4Y() - (playerB.GetY2() + playerB.GetY1()) / 2 < 140 &&
			playerA.Getweapon_Continue4X() - ((playerB.GetX1() + playerB.GetX2()) / 2) > -10 &&
			playerA.Getweapon_Continue4X() - ((playerB.GetX1() + playerB.GetX2()) / 2) < 5)
			playerB.Setb2(-2);

		if (playerA.Getweapon_Continue5Y() - (playerB.GetY2() + playerB.GetY1()) / 2 > 70 &&
			playerA.Getweapon_Continue5Y() - (playerB.GetY2() + playerB.GetY1()) / 2 < 140 &&
			playerA.Getweapon_Continue5X() - ((playerB.GetX1() + playerB.GetX2()) / 2) > -10 &&
			playerA.Getweapon_Continue5X() - ((playerB.GetX1() + playerB.GetX2()) / 2) < 5)
			playerB.Setb2(-2);

		//////////// B的普通攻擊 A扣血設定 //////////// 
		if (playerB.GetWeaponY() - ((playerA.GetY1() + playerA.GetY2()) / 2) > -10 &&
			playerB.GetWeaponY() - ((playerA.GetY1() + playerA.GetY2()) / 2) < 60 &&

			playerB.GetWeaponX() - ((playerA.GetX1() + playerA.GetX2()) / 2) > 0 &&
			playerB.GetWeaponX() - ((playerA.GetX1() + playerA.GetX2()) / 2) < 15){
			playerA.Setb1(-1);
			playerB.WeaponMissing();
		}


		//////////////// A的防前跳 B扣血設定////////////////
		if (playerA.GetWeaponBallY() - ((playerB.GetY1() + playerB.GetY2()) / 2) > -5 &&
			playerA.GetWeaponBallY() - ((playerB.GetY1() + playerB.GetY2()) / 2) < 55 &&

			playerA.GetWeaponBallX() - ((playerB.GetX1() + playerB.GetX2()) / 2) > -10 &&
			playerA.GetWeaponBallX() - ((playerB.GetX1() + playerB.GetX2()) / 2) < 5)
			playerB.Setb2(-5);

		//////////////// A的防上攻 B扣血設定////////////////
		if (playerA.GetWeapon4Y() - ((playerB.GetY1() + playerB.GetY2()) / 2) > -5 &&
			playerA.GetWeapon4Y() - ((playerB.GetY1() + playerB.GetY2()) / 2) < 55 &&

			playerA.GetWeapon4X() - ((playerB.GetX1() + playerB.GetX2()) / 2) > -10 &&
			playerA.GetWeapon4X() - ((playerB.GetX1() + playerB.GetX2()) / 2) < 5)
			playerB.Setb2(-10);


		///////////////////////////////////////////


		blood1.SetTopLeft(20, 30);
		blood10.SetTopLeft(24, 30);
		blood11.SetTopLeft(28, 30);
		blood12.SetTopLeft(32, 30);
		blood13.SetTopLeft(36, 30);
		blood14.SetTopLeft(40, 30);
		blood15.SetTopLeft(44, 30);
		blood16.SetTopLeft(48, 30);
		blood17.SetTopLeft(52, 30);
		blood18.SetTopLeft(56, 30);
		blood19.SetTopLeft(60, 30);

		blood2.SetTopLeft(64, 30);
		blood20.SetTopLeft(68, 30);
		blood21.SetTopLeft(72, 30);
		blood22.SetTopLeft(76, 30);
		blood23.SetTopLeft(80, 30);
		blood24.SetTopLeft(84, 30);
		blood25.SetTopLeft(88, 30);
		blood26.SetTopLeft(92, 30);
		blood27.SetTopLeft(96, 30);
		blood28.SetTopLeft(100, 30);
		blood29.SetTopLeft(104, 30);

		blood3.SetTopLeft(108, 30);
		blood30.SetTopLeft(112, 30);
		blood31.SetTopLeft(116, 30);
		blood32.SetTopLeft(120, 30);
		blood33.SetTopLeft(124, 30);
		blood34.SetTopLeft(128, 30);
		blood35.SetTopLeft(132, 30);
		blood36.SetTopLeft(136, 30);
		blood37.SetTopLeft(140, 30);
		blood38.SetTopLeft(144, 30);
		blood39.SetTopLeft(148, 30);

		blood4.SetTopLeft(152, 30);
		blood40.SetTopLeft(156, 30);
		blood41.SetTopLeft(160, 30);
		blood42.SetTopLeft(164, 30);
		blood43.SetTopLeft(168, 30);
		blood44.SetTopLeft(172, 30);
		blood45.SetTopLeft(176, 30);
		blood46.SetTopLeft(180, 30);
		blood47.SetTopLeft(184, 30);
		blood48.SetTopLeft(188, 30);
		blood49.SetTopLeft(192, 30);


		blood5.SetTopLeft(196, 30);
		blood50.SetTopLeft(200, 30);
		blood51.SetTopLeft(204, 30);
		blood52.SetTopLeft(208, 30);
		blood53.SetTopLeft(212, 30);
		blood54.SetTopLeft(216, 30);
		blood55.SetTopLeft(220, 30);
		blood56.SetTopLeft(224, 30);
		blood57.SetTopLeft(228, 30);
		blood58.SetTopLeft(232, 30);
		blood59.SetTopLeft(236, 30);

		blood6.SetTopLeft(240, 30);
		blood60.SetTopLeft(244, 30);
		blood61.SetTopLeft(248, 30);
		blood62.SetTopLeft(252, 30);
		blood63.SetTopLeft(256, 30);
		blood64.SetTopLeft(260, 30);
		blood65.SetTopLeft(264, 30);
		blood66.SetTopLeft(268, 30);
		blood67.SetTopLeft(272, 30);
		blood68.SetTopLeft(276, 30);
		blood69.SetTopLeft(280, 30);

		blood7.SetTopLeft(284, 30);
		//////////////////////////////////////////

		blood_2_1.SetTopLeft(20 + 490, 30);
		blood_2_10.SetTopLeft(24 + 490, 30);
		blood_2_11.SetTopLeft(28 + 490, 30);
		blood_2_12.SetTopLeft(32 + 490, 30);
		blood_2_13.SetTopLeft(36 + 490, 30);
		blood_2_14.SetTopLeft(40 + 490, 30);
		blood_2_15.SetTopLeft(44 + 490, 30);
		blood_2_16.SetTopLeft(48 + 490, 30);
		blood_2_17.SetTopLeft(52 + 490, 30);
		blood_2_18.SetTopLeft(56 + 490, 30);
		blood_2_19.SetTopLeft(60 + 490, 30);

		blood_2_2.SetTopLeft(64 + 490, 30);
		blood_2_20.SetTopLeft(68 + 490, 30);
		blood_2_21.SetTopLeft(72 + 490, 30);
		blood_2_22.SetTopLeft(76 + 490, 30);
		blood_2_23.SetTopLeft(80 + 490, 30);
		blood_2_24.SetTopLeft(84 + 490, 30);
		blood_2_25.SetTopLeft(88 + 490, 30);
		blood_2_26.SetTopLeft(92 + 490, 30);
		blood_2_27.SetTopLeft(96 + 490, 30);
		blood_2_28.SetTopLeft(100 + 490, 30);
		blood_2_29.SetTopLeft(104 + 490, 30);

		blood_2_3.SetTopLeft(108 + 490, 30);
		blood_2_30.SetTopLeft(112 + 490, 30);
		blood_2_31.SetTopLeft(116 + 490, 30);
		blood_2_32.SetTopLeft(120 + 490, 30);
		blood_2_33.SetTopLeft(124 + 490, 30);
		blood_2_34.SetTopLeft(128 + 490, 30);
		blood_2_35.SetTopLeft(132 + 490, 30);
		blood_2_36.SetTopLeft(136 + 490, 30);
		blood_2_37.SetTopLeft(140 + 490, 30);
		blood_2_38.SetTopLeft(144 + 490, 30);
		blood_2_39.SetTopLeft(148 + 490, 30);

		blood_2_4.SetTopLeft(152 + 490, 30);
		blood_2_40.SetTopLeft(156 + 490, 30);
		blood_2_41.SetTopLeft(160 + 490, 30);
		blood_2_42.SetTopLeft(164 + 490, 30);
		blood_2_43.SetTopLeft(168 + 490, 30);
		blood_2_44.SetTopLeft(172 + 490, 30);
		blood_2_45.SetTopLeft(176 + 490, 30);
		blood_2_46.SetTopLeft(180 + 490, 30);
		blood_2_47.SetTopLeft(184 + 490, 30);
		blood_2_48.SetTopLeft(188 + 490, 30);
		blood_2_49.SetTopLeft(192 + 490, 30);


		blood_2_5.SetTopLeft(196 + 490, 30);
		blood_2_50.SetTopLeft(200 + 490, 30);
		blood_2_51.SetTopLeft(204 + 490, 30);
		blood_2_52.SetTopLeft(208 + 490, 30);
		blood_2_53.SetTopLeft(212 + 490, 30);
		blood_2_54.SetTopLeft(216 + 490, 30);
		blood_2_55.SetTopLeft(220 + 490, 30);
		blood_2_56.SetTopLeft(224 + 490, 30);
		blood_2_57.SetTopLeft(228 + 490, 30);
		blood_2_58.SetTopLeft(232 + 490, 30);
		blood_2_59.SetTopLeft(236 + 490, 30);

		blood_2_6.SetTopLeft(240 + 490, 30);
		blood_2_60.SetTopLeft(244 + 490, 30);
		blood_2_61.SetTopLeft(248 + 490, 30);
		blood_2_62.SetTopLeft(252 + 490, 30);
		blood_2_63.SetTopLeft(256 + 490, 30);
		blood_2_64.SetTopLeft(260 + 490, 30);
		blood_2_65.SetTopLeft(264 + 490, 30);
		blood_2_66.SetTopLeft(268 + 490, 30);
		blood_2_67.SetTopLeft(272 + 490, 30);
		blood_2_68.SetTopLeft(276 + 490, 30);
		blood_2_69.SetTopLeft(280 + 490, 30);

		blood_2_7.SetTopLeft(284 + 490, 30);
		////////////////////////////////////////////




		mana1.SetTopLeft(20, 75);
		mana10.SetTopLeft(24, 75);
		mana11.SetTopLeft(28, 75);
		mana12.SetTopLeft(32, 75);
		mana13.SetTopLeft(36, 75);
		mana14.SetTopLeft(40, 75);
		mana15.SetTopLeft(44, 75);
		mana16.SetTopLeft(48, 75);
		mana17.SetTopLeft(52, 75);
		mana18.SetTopLeft(56, 75);
		mana19.SetTopLeft(60, 75);

		mana2.SetTopLeft(64, 75);
		mana20.SetTopLeft(68, 75);
		mana21.SetTopLeft(72, 75);
		mana22.SetTopLeft(76, 75);
		mana23.SetTopLeft(80, 75);
		mana24.SetTopLeft(84, 75);
		mana25.SetTopLeft(88, 75);
		mana26.SetTopLeft(92, 75);
		mana27.SetTopLeft(96, 75);
		mana28.SetTopLeft(100, 75);
		mana29.SetTopLeft(104, 75);

		mana3.SetTopLeft(108, 75);
		mana30.SetTopLeft(112, 75);
		mana31.SetTopLeft(116, 75);
		mana32.SetTopLeft(120, 75);
		mana33.SetTopLeft(124, 75);
		mana34.SetTopLeft(128, 75);
		mana35.SetTopLeft(132, 75);
		mana36.SetTopLeft(136, 75);
		mana37.SetTopLeft(140, 75);
		mana38.SetTopLeft(144, 75);
		mana39.SetTopLeft(148, 75);

		mana4.SetTopLeft(152, 75);
		mana40.SetTopLeft(156, 75);
		mana41.SetTopLeft(160, 75);
		mana42.SetTopLeft(164, 75);
		mana43.SetTopLeft(168, 75);
		mana44.SetTopLeft(172, 75);
		mana45.SetTopLeft(176, 75);
		mana46.SetTopLeft(180, 75);
		mana47.SetTopLeft(184, 75);
		mana48.SetTopLeft(188, 75);
		mana49.SetTopLeft(192, 75);


		mana5.SetTopLeft(196, 75);
		mana50.SetTopLeft(200, 75);
		mana51.SetTopLeft(204, 75);
		mana52.SetTopLeft(208, 75);
		mana53.SetTopLeft(212, 75);
		mana54.SetTopLeft(216, 75);
		mana55.SetTopLeft(220, 75);
		mana56.SetTopLeft(224, 75);
		mana57.SetTopLeft(228, 75);
		mana58.SetTopLeft(232, 75);
		mana59.SetTopLeft(236, 75);

		mana6.SetTopLeft(240, 75);
		mana60.SetTopLeft(244, 75);
		mana61.SetTopLeft(248, 75);
		mana62.SetTopLeft(252, 75);
		mana63.SetTopLeft(256, 75);
		mana64.SetTopLeft(260, 75);
		mana65.SetTopLeft(264, 75);
		mana66.SetTopLeft(268, 75);
		mana67.SetTopLeft(272, 75);
		mana68.SetTopLeft(276, 75);
		mana69.SetTopLeft(280, 75);

		mana7.SetTopLeft(284, 75);

		///////////////////////////////////////


		mana_2_1.SetTopLeft(20 + 490, 75);
		mana_2_10.SetTopLeft(24 + 490, 75);
		mana_2_11.SetTopLeft(28 + 490, 75);
		mana_2_12.SetTopLeft(32 + 490, 75);
		mana_2_13.SetTopLeft(36 + 490, 75);
		mana_2_14.SetTopLeft(40 + 490, 75);
		mana_2_15.SetTopLeft(44 + 490, 75);
		mana_2_16.SetTopLeft(48 + 490, 75);
		mana_2_17.SetTopLeft(52 + 490, 75);
		mana_2_18.SetTopLeft(56 + 490, 75);
		mana_2_19.SetTopLeft(60 + 490, 75);

		mana_2_2.SetTopLeft(64 + 490, 75);
		mana_2_20.SetTopLeft(68 + 490, 75);
		mana_2_21.SetTopLeft(72 + 490, 75);
		mana_2_22.SetTopLeft(76 + 490, 75);
		mana_2_23.SetTopLeft(80 + 490, 75);
		mana_2_24.SetTopLeft(84 + 490, 75);
		mana_2_25.SetTopLeft(88 + 490, 75);
		mana_2_26.SetTopLeft(92 + 490, 75);
		mana_2_27.SetTopLeft(96 + 490, 75);
		mana_2_28.SetTopLeft(100 + 490, 75);
		mana_2_29.SetTopLeft(104 + 490, 75);

		mana_2_3.SetTopLeft(108 + 490, 75);
		mana_2_30.SetTopLeft(112 + 490, 75);
		mana_2_31.SetTopLeft(116 + 490, 75);
		mana_2_32.SetTopLeft(120 + 490, 75);
		mana_2_33.SetTopLeft(124 + 490, 75);
		mana_2_34.SetTopLeft(128 + 490, 75);
		mana_2_35.SetTopLeft(132 + 490, 75);
		mana_2_36.SetTopLeft(136 + 490, 75);
		mana_2_37.SetTopLeft(140 + 490, 75);
		mana_2_38.SetTopLeft(144 + 490, 75);
		mana_2_39.SetTopLeft(148 + 490, 75);

		mana_2_4.SetTopLeft(152 + 490, 75);
		mana_2_40.SetTopLeft(156 + 490, 75);
		mana_2_41.SetTopLeft(160 + 490, 75);
		mana_2_42.SetTopLeft(164 + 490, 75);
		mana_2_43.SetTopLeft(168 + 490, 75);
		mana_2_44.SetTopLeft(172 + 490, 75);
		mana_2_45.SetTopLeft(176 + 490, 75);
		mana_2_46.SetTopLeft(180 + 490, 75);
		mana_2_47.SetTopLeft(184 + 490, 75);
		mana_2_48.SetTopLeft(188 + 490, 75);
		mana_2_49.SetTopLeft(192 + 490, 75);


		mana_2_5.SetTopLeft(196 + 490, 75);
		mana_2_50.SetTopLeft(200 + 490, 75);
		mana_2_51.SetTopLeft(204 + 490, 75);
		mana_2_52.SetTopLeft(208 + 490, 75);
		mana_2_53.SetTopLeft(212 + 490, 75);
		mana_2_54.SetTopLeft(216 + 490, 75);
		mana_2_55.SetTopLeft(220 + 490, 75);
		mana_2_56.SetTopLeft(224 + 490, 75);
		mana_2_57.SetTopLeft(228 + 490, 75);
		mana_2_58.SetTopLeft(232 + 490, 75);
		mana_2_59.SetTopLeft(236 + 490, 75);

		mana_2_6.SetTopLeft(240 + 490, 75);
		mana_2_60.SetTopLeft(244 + 490, 75);
		mana_2_61.SetTopLeft(248 + 490, 75);
		mana_2_62.SetTopLeft(252 + 490, 75);
		mana_2_63.SetTopLeft(256 + 490, 75);
		mana_2_64.SetTopLeft(260 + 490, 75);
		mana_2_65.SetTopLeft(264 + 490, 75);
		mana_2_66.SetTopLeft(268 + 490, 75);
		mana_2_67.SetTopLeft(272 + 490, 75);
		mana_2_68.SetTopLeft(276 + 490, 75);
		mana_2_69.SetTopLeft(280 + 490, 75);

		mana_2_7.SetTopLeft(284 + 490, 75);

		//////////////////////////////////////////////////

		endA.SetTopLeft(0, 0);
		endA.OnMove();

		endB.SetTopLeft(0, 0);
		endB.OnMove();




		int i;
		for (i = 0; i < NUMBALLS; i++)
			ball[i].OnMove();
		//
		// 移動擦子
		//
		eraser.OnMove();


		playerA.OnMove();
		playerB.OnMove();

		tool1A.GetPlayerA_X(playerA.GetX_forTool(tool1A.GetTool1Number(), tool1A.GetTool2Number(), tool1A.GetTool3Number()));
		tool1A.GetPlayerA_Y(playerA.GetY_forTool(tool1A.GetTool1Number(), tool1A.GetTool2Number(), tool1A.GetTool3Number()));

		tool1A.GetPlayerB_X(playerB.GetX_forTool(tool1A.GetTool1Number(), tool1A.GetTool2Number(), tool1A.GetTool3Number()));
		tool1A.GetPlayerB_Y(playerB.GetY_forTool(tool1A.GetTool1Number(), tool1A.GetTool2Number(), tool1A.GetTool3Number()));

		tool1A.OnMove();

		///// 裝飾用道具 /////
		tool1B.GetPlayerA_X(playerA.GetX_forTool(tool1B.GetTool1Number(), tool1B.GetTool2Number(), tool1B.GetTool3Number()));
		tool1B.GetPlayerA_Y(playerA.GetY_forTool(tool1B.GetTool1Number(), tool1B.GetTool2Number(), tool1B.GetTool3Number()));
		tool1B.GetPlayerB_X(playerB.GetX_forTool(tool1B.GetTool1Number(), tool1B.GetTool2Number(), tool1B.GetTool3Number()));
		tool1B.GetPlayerB_Y(playerB.GetY_forTool(tool1B.GetTool1Number(), tool1B.GetTool2Number(), tool1B.GetTool3Number()));
		tool1B.OnMove();
		tool1C.GetPlayerA_X(playerA.GetX_forTool(tool1C.GetTool1Number(), tool1C.GetTool2Number(), tool1C.GetTool3Number()));
		tool1C.GetPlayerA_Y(playerA.GetY_forTool(tool1C.GetTool1Number(), tool1C.GetTool2Number(), tool1C.GetTool3Number()));
		tool1C.GetPlayerB_X(playerB.GetX_forTool(tool1C.GetTool1Number(), tool1C.GetTool2Number(), tool1C.GetTool3Number()));
		tool1C.GetPlayerB_Y(playerB.GetY_forTool(tool1C.GetTool1Number(), tool1C.GetTool2Number(), tool1C.GetTool3Number()));
		tool1C.OnMove();

		tool2A.GetPlayerA_X(playerA.GetX_forTool(tool2A.GetTool1Number(), tool2A.GetTool2Number(), tool2A.GetTool3Number()));
		tool2A.GetPlayerA_Y(playerA.GetY_forTool(tool2A.GetTool1Number(), tool2A.GetTool2Number(), tool2A.GetTool3Number()));
		tool2A.GetPlayerB_X(playerB.GetX_forTool(tool2A.GetTool1Number(), tool2A.GetTool2Number(), tool2A.GetTool3Number()));
		tool2A.GetPlayerB_Y(playerB.GetY_forTool(tool2A.GetTool1Number(), tool2A.GetTool2Number(), tool2A.GetTool3Number()));
		tool2A.OnMove();
		tool2B.GetPlayerA_X(playerA.GetX_forTool(tool2B.GetTool1Number(), tool2B.GetTool2Number(), tool2B.GetTool3Number()));
		tool2B.GetPlayerA_Y(playerA.GetY_forTool(tool2B.GetTool1Number(), tool2B.GetTool2Number(), tool2B.GetTool3Number()));
		tool2B.GetPlayerB_X(playerB.GetX_forTool(tool2B.GetTool1Number(), tool2B.GetTool2Number(), tool2B.GetTool3Number()));
		tool2B.GetPlayerB_Y(playerB.GetY_forTool(tool2B.GetTool1Number(), tool2B.GetTool2Number(), tool2B.GetTool3Number()));
		tool2B.OnMove();
		tool2C.GetPlayerA_X(playerA.GetX_forTool(tool2C.GetTool1Number(), tool2C.GetTool2Number(), tool2C.GetTool3Number()));
		tool2C.GetPlayerA_Y(playerA.GetY_forTool(tool2C.GetTool1Number(), tool2C.GetTool2Number(), tool2C.GetTool3Number()));
		tool2C.GetPlayerB_X(playerB.GetX_forTool(tool2C.GetTool1Number(), tool2C.GetTool2Number(), tool2C.GetTool3Number()));
		tool2C.GetPlayerB_Y(playerB.GetY_forTool(tool2C.GetTool1Number(), tool2C.GetTool2Number(), tool2C.GetTool3Number()));
		tool2C.OnMove();

		tool3A.GetPlayerA_X(playerA.GetX_forTool(tool3A.GetTool1Number(), tool3A.GetTool2Number(), tool3A.GetTool3Number()));
		tool3A.GetPlayerA_Y(playerA.GetY_forTool(tool3A.GetTool1Number(), tool3A.GetTool2Number(), tool3A.GetTool3Number()));
		tool3A.GetPlayerB_X(playerB.GetX_forTool(tool3A.GetTool1Number(), tool3A.GetTool2Number(), tool3A.GetTool3Number()));
		tool3A.GetPlayerB_Y(playerB.GetY_forTool(tool3A.GetTool1Number(), tool3A.GetTool2Number(), tool3A.GetTool3Number()));
		tool3A.OnMove();
		tool3B.GetPlayerA_X(playerA.GetX_forTool(tool3B.GetTool1Number(), tool3B.GetTool2Number(), tool3B.GetTool3Number()));
		tool3B.GetPlayerA_Y(playerA.GetY_forTool(tool3B.GetTool1Number(), tool3B.GetTool2Number(), tool3B.GetTool3Number()));
		tool3B.GetPlayerB_X(playerB.GetX_forTool(tool3B.GetTool1Number(), tool3B.GetTool2Number(), tool3B.GetTool3Number()));
		tool3B.GetPlayerB_Y(playerB.GetY_forTool(tool3B.GetTool1Number(), tool3B.GetTool2Number(), tool3B.GetTool3Number()));
		tool3B.OnMove();
		tool3C.GetPlayerA_X(playerA.GetX_forTool(tool3C.GetTool1Number(), tool3C.GetTool2Number(), tool3C.GetTool3Number()));
		tool3C.GetPlayerA_Y(playerA.GetY_forTool(tool3C.GetTool1Number(), tool3C.GetTool2Number(), tool3C.GetTool3Number()));
		tool3C.GetPlayerB_X(playerB.GetX_forTool(tool3C.GetTool1Number(), tool3C.GetTool2Number(), tool3C.GetTool3Number()));
		tool3C.GetPlayerB_Y(playerB.GetY_forTool(tool3C.GetTool1Number(), tool3C.GetTool2Number(), tool3C.GetTool3Number()));
		tool3C.OnMove();
		//
		// 判斷擦子是否碰到球
		//
		for (i = 0; i < NUMBALLS; i++)
			if (ball[i].IsAlive() && ball[i].HitEraser(&eraser))
			{
				ball[i].SetIsAlive(false);
				//				CAudio::Instance()->Play(AUDIO_DING);
				hits_left.Add(-1);
				//
				// 若剩餘碰撞次數為0，則跳到Game Over狀態
				//
				if (hits_left.GetInteger() <= 0)
				{
					CAudio::Instance()->Stop(AUDIO_LAKE);	// 停止 WAVE
					CAudio::Instance()->Stop(AUDIO_NTUT);	// 停止 MIDI
					GotoGameState(GAME_STATE_OVER);
				}
			}
		//
		// 移動彈跳的球
		//
		bball.OnMove();

	}

	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
		//
		// 開始載入資料
		//

		I_am_counter = 0;

		Last_ALeft = 0;
		Last_ARight = 0;
		A_lastClick = 0;

		Last_BLeft = 0;
		Last_BRight = 0;
		B_lastClick = 0;
		firstTool = 0;

		int i;
		for (i = 0; i < NUMBALLS; i++)
			ball[i].LoadBitmap();								// 載入第i個球的圖形
		eraser.LoadBitmap();
		background.LoadBitmap(IDB_mapA);					// 載入背景的圖形


		bar.LoadBitmap(IDB_bar);
		playerA_logo.LoadBitmap(IDB_playerA_logo, RGB(255, 255, 255));			// 人物A頭像
		playerB_logo.LoadBitmap(IDB_playerB_logo, RGB(255, 255, 255));			// 人物B頭像

		tool1A.LoadBitmap();
		tool1B.LoadBitmap();
		tool1C.LoadBitmap();
		tool2A.LoadBitmap();
		tool2B.LoadBitmap();
		tool2C.LoadBitmap();
		tool3A.LoadBitmap();
		tool3B.LoadBitmap();
		tool3C.LoadBitmap();
		///////////////////////////////////////////////////////

		blood1.LoadBitmap(IDB_blood);
		blood10.LoadBitmap(IDB_blood);
		blood11.LoadBitmap(IDB_blood);
		blood12.LoadBitmap(IDB_blood);
		blood13.LoadBitmap(IDB_blood);
		blood14.LoadBitmap(IDB_blood);
		blood15.LoadBitmap(IDB_blood);
		blood16.LoadBitmap(IDB_blood);
		blood17.LoadBitmap(IDB_blood);
		blood18.LoadBitmap(IDB_blood);
		blood19.LoadBitmap(IDB_blood);

		blood2.LoadBitmap(IDB_blood);
		blood20.LoadBitmap(IDB_blood);
		blood21.LoadBitmap(IDB_blood);
		blood22.LoadBitmap(IDB_blood);
		blood23.LoadBitmap(IDB_blood);
		blood24.LoadBitmap(IDB_blood);
		blood25.LoadBitmap(IDB_blood);
		blood26.LoadBitmap(IDB_blood);
		blood27.LoadBitmap(IDB_blood);
		blood28.LoadBitmap(IDB_blood);
		blood29.LoadBitmap(IDB_blood);

		blood3.LoadBitmap(IDB_blood);
		blood30.LoadBitmap(IDB_blood);
		blood31.LoadBitmap(IDB_blood);
		blood32.LoadBitmap(IDB_blood);
		blood33.LoadBitmap(IDB_blood);
		blood34.LoadBitmap(IDB_blood);
		blood35.LoadBitmap(IDB_blood);
		blood36.LoadBitmap(IDB_blood);
		blood37.LoadBitmap(IDB_blood);
		blood38.LoadBitmap(IDB_blood);
		blood39.LoadBitmap(IDB_blood);

		blood4.LoadBitmap(IDB_blood);
		blood40.LoadBitmap(IDB_blood);
		blood41.LoadBitmap(IDB_blood);
		blood42.LoadBitmap(IDB_blood);
		blood43.LoadBitmap(IDB_blood);
		blood44.LoadBitmap(IDB_blood);
		blood45.LoadBitmap(IDB_blood);
		blood46.LoadBitmap(IDB_blood);
		blood47.LoadBitmap(IDB_blood);
		blood48.LoadBitmap(IDB_blood);
		blood49.LoadBitmap(IDB_blood);


		blood5.LoadBitmap(IDB_blood);
		blood50.LoadBitmap(IDB_blood);
		blood51.LoadBitmap(IDB_blood);
		blood52.LoadBitmap(IDB_blood);
		blood53.LoadBitmap(IDB_blood);
		blood54.LoadBitmap(IDB_blood);
		blood55.LoadBitmap(IDB_blood);
		blood56.LoadBitmap(IDB_blood);
		blood57.LoadBitmap(IDB_blood);
		blood58.LoadBitmap(IDB_blood);
		blood59.LoadBitmap(IDB_blood);


		blood6.LoadBitmap(IDB_blood);
		blood60.LoadBitmap(IDB_blood);
		blood61.LoadBitmap(IDB_blood);
		blood62.LoadBitmap(IDB_blood);
		blood63.LoadBitmap(IDB_blood);
		blood64.LoadBitmap(IDB_blood);
		blood65.LoadBitmap(IDB_blood);
		blood66.LoadBitmap(IDB_blood);
		blood67.LoadBitmap(IDB_blood);
		blood68.LoadBitmap(IDB_blood);
		blood69.LoadBitmap(IDB_blood);

		blood7.LoadBitmap(IDB_blood);
		/////////////////////////////////////////////////////////////

		blood_2_1.LoadBitmap(IDB_blood);
		blood_2_10.LoadBitmap(IDB_blood);
		blood_2_11.LoadBitmap(IDB_blood);
		blood_2_12.LoadBitmap(IDB_blood);
		blood_2_13.LoadBitmap(IDB_blood);
		blood_2_14.LoadBitmap(IDB_blood);
		blood_2_15.LoadBitmap(IDB_blood);
		blood_2_16.LoadBitmap(IDB_blood);
		blood_2_17.LoadBitmap(IDB_blood);
		blood_2_18.LoadBitmap(IDB_blood);
		blood_2_19.LoadBitmap(IDB_blood);

		blood_2_2.LoadBitmap(IDB_blood);
		blood_2_20.LoadBitmap(IDB_blood);
		blood_2_21.LoadBitmap(IDB_blood);
		blood_2_22.LoadBitmap(IDB_blood);
		blood_2_23.LoadBitmap(IDB_blood);
		blood_2_24.LoadBitmap(IDB_blood);
		blood_2_25.LoadBitmap(IDB_blood);
		blood_2_26.LoadBitmap(IDB_blood);
		blood_2_27.LoadBitmap(IDB_blood);
		blood_2_28.LoadBitmap(IDB_blood);
		blood_2_29.LoadBitmap(IDB_blood);

		blood_2_3.LoadBitmap(IDB_blood);
		blood_2_30.LoadBitmap(IDB_blood);
		blood_2_31.LoadBitmap(IDB_blood);
		blood_2_32.LoadBitmap(IDB_blood);
		blood_2_33.LoadBitmap(IDB_blood);
		blood_2_34.LoadBitmap(IDB_blood);
		blood_2_35.LoadBitmap(IDB_blood);
		blood_2_36.LoadBitmap(IDB_blood);
		blood_2_37.LoadBitmap(IDB_blood);
		blood_2_38.LoadBitmap(IDB_blood);
		blood_2_39.LoadBitmap(IDB_blood);

		blood_2_4.LoadBitmap(IDB_blood);
		blood_2_40.LoadBitmap(IDB_blood);
		blood_2_41.LoadBitmap(IDB_blood);
		blood_2_42.LoadBitmap(IDB_blood);
		blood_2_43.LoadBitmap(IDB_blood);
		blood_2_44.LoadBitmap(IDB_blood);
		blood_2_45.LoadBitmap(IDB_blood);
		blood_2_46.LoadBitmap(IDB_blood);
		blood_2_47.LoadBitmap(IDB_blood);
		blood_2_48.LoadBitmap(IDB_blood);
		blood_2_49.LoadBitmap(IDB_blood);


		blood_2_5.LoadBitmap(IDB_blood);
		blood_2_50.LoadBitmap(IDB_blood);
		blood_2_51.LoadBitmap(IDB_blood);
		blood_2_52.LoadBitmap(IDB_blood);
		blood_2_53.LoadBitmap(IDB_blood);
		blood_2_54.LoadBitmap(IDB_blood);
		blood_2_55.LoadBitmap(IDB_blood);
		blood_2_56.LoadBitmap(IDB_blood);
		blood_2_57.LoadBitmap(IDB_blood);
		blood_2_58.LoadBitmap(IDB_blood);
		blood_2_59.LoadBitmap(IDB_blood);


		blood_2_6.LoadBitmap(IDB_blood);
		blood_2_60.LoadBitmap(IDB_blood);
		blood_2_61.LoadBitmap(IDB_blood);
		blood_2_62.LoadBitmap(IDB_blood);
		blood_2_63.LoadBitmap(IDB_blood);
		blood_2_64.LoadBitmap(IDB_blood);
		blood_2_65.LoadBitmap(IDB_blood);
		blood_2_66.LoadBitmap(IDB_blood);
		blood_2_67.LoadBitmap(IDB_blood);
		blood_2_68.LoadBitmap(IDB_blood);
		blood_2_69.LoadBitmap(IDB_blood);

		blood_2_7.LoadBitmap(IDB_blood);

		//////////////////////////////////////////////////////////////

		mana1.LoadBitmap(IDB_mana);
		mana10.LoadBitmap(IDB_mana);
		mana11.LoadBitmap(IDB_mana);
		mana12.LoadBitmap(IDB_mana);
		mana13.LoadBitmap(IDB_mana);
		mana14.LoadBitmap(IDB_mana);
		mana15.LoadBitmap(IDB_mana);
		mana16.LoadBitmap(IDB_mana);
		mana17.LoadBitmap(IDB_mana);
		mana18.LoadBitmap(IDB_mana);
		mana19.LoadBitmap(IDB_mana);

		mana2.LoadBitmap(IDB_mana);
		mana20.LoadBitmap(IDB_mana);
		mana21.LoadBitmap(IDB_mana);
		mana22.LoadBitmap(IDB_mana);
		mana23.LoadBitmap(IDB_mana);
		mana24.LoadBitmap(IDB_mana);
		mana25.LoadBitmap(IDB_mana);
		mana26.LoadBitmap(IDB_mana);
		mana27.LoadBitmap(IDB_mana);
		mana28.LoadBitmap(IDB_mana);
		mana29.LoadBitmap(IDB_mana);

		mana3.LoadBitmap(IDB_mana);
		mana30.LoadBitmap(IDB_mana);
		mana31.LoadBitmap(IDB_mana);
		mana32.LoadBitmap(IDB_mana);
		mana33.LoadBitmap(IDB_mana);
		mana34.LoadBitmap(IDB_mana);
		mana35.LoadBitmap(IDB_mana);
		mana36.LoadBitmap(IDB_mana);
		mana37.LoadBitmap(IDB_mana);
		mana38.LoadBitmap(IDB_mana);
		mana39.LoadBitmap(IDB_mana);

		mana4.LoadBitmap(IDB_mana);
		mana40.LoadBitmap(IDB_mana);
		mana41.LoadBitmap(IDB_mana);
		mana42.LoadBitmap(IDB_mana);
		mana43.LoadBitmap(IDB_mana);
		mana44.LoadBitmap(IDB_mana);
		mana45.LoadBitmap(IDB_mana);
		mana46.LoadBitmap(IDB_mana);
		mana47.LoadBitmap(IDB_mana);
		mana48.LoadBitmap(IDB_mana);
		mana49.LoadBitmap(IDB_mana);


		mana5.LoadBitmap(IDB_mana);
		mana50.LoadBitmap(IDB_mana);
		mana51.LoadBitmap(IDB_mana);
		mana52.LoadBitmap(IDB_mana);
		mana53.LoadBitmap(IDB_mana);
		mana54.LoadBitmap(IDB_mana);
		mana55.LoadBitmap(IDB_mana);
		mana56.LoadBitmap(IDB_mana);
		mana57.LoadBitmap(IDB_mana);
		mana58.LoadBitmap(IDB_mana);
		mana59.LoadBitmap(IDB_mana);


		mana6.LoadBitmap(IDB_mana);
		mana60.LoadBitmap(IDB_mana);
		mana61.LoadBitmap(IDB_mana);
		mana62.LoadBitmap(IDB_mana);
		mana63.LoadBitmap(IDB_mana);
		mana64.LoadBitmap(IDB_mana);
		mana65.LoadBitmap(IDB_mana);
		mana66.LoadBitmap(IDB_mana);
		mana67.LoadBitmap(IDB_mana);
		mana68.LoadBitmap(IDB_mana);
		mana69.LoadBitmap(IDB_mana);

		mana7.LoadBitmap(IDB_mana);
		////////////////////////////////////////////////

		mana_2_1.LoadBitmap(IDB_mana);
		mana_2_10.LoadBitmap(IDB_mana);
		mana_2_11.LoadBitmap(IDB_mana);
		mana_2_12.LoadBitmap(IDB_mana);
		mana_2_13.LoadBitmap(IDB_mana);
		mana_2_14.LoadBitmap(IDB_mana);
		mana_2_15.LoadBitmap(IDB_mana);
		mana_2_16.LoadBitmap(IDB_mana);
		mana_2_17.LoadBitmap(IDB_mana);
		mana_2_18.LoadBitmap(IDB_mana);
		mana_2_19.LoadBitmap(IDB_mana);

		mana_2_2.LoadBitmap(IDB_mana);
		mana_2_20.LoadBitmap(IDB_mana);
		mana_2_21.LoadBitmap(IDB_mana);
		mana_2_22.LoadBitmap(IDB_mana);
		mana_2_23.LoadBitmap(IDB_mana);
		mana_2_24.LoadBitmap(IDB_mana);
		mana_2_25.LoadBitmap(IDB_mana);
		mana_2_26.LoadBitmap(IDB_mana);
		mana_2_27.LoadBitmap(IDB_mana);
		mana_2_28.LoadBitmap(IDB_mana);
		mana_2_29.LoadBitmap(IDB_mana);

		mana_2_3.LoadBitmap(IDB_mana);
		mana_2_30.LoadBitmap(IDB_mana);
		mana_2_31.LoadBitmap(IDB_mana);
		mana_2_32.LoadBitmap(IDB_mana);
		mana_2_33.LoadBitmap(IDB_mana);
		mana_2_34.LoadBitmap(IDB_mana);
		mana_2_35.LoadBitmap(IDB_mana);
		mana_2_36.LoadBitmap(IDB_mana);
		mana_2_37.LoadBitmap(IDB_mana);
		mana_2_38.LoadBitmap(IDB_mana);
		mana_2_39.LoadBitmap(IDB_mana);

		mana_2_4.LoadBitmap(IDB_mana);
		mana_2_40.LoadBitmap(IDB_mana);
		mana_2_41.LoadBitmap(IDB_mana);
		mana_2_42.LoadBitmap(IDB_mana);
		mana_2_43.LoadBitmap(IDB_mana);
		mana_2_44.LoadBitmap(IDB_mana);
		mana_2_45.LoadBitmap(IDB_mana);
		mana_2_46.LoadBitmap(IDB_mana);
		mana_2_47.LoadBitmap(IDB_mana);
		mana_2_48.LoadBitmap(IDB_mana);
		mana_2_49.LoadBitmap(IDB_mana);


		mana_2_5.LoadBitmap(IDB_mana);
		mana_2_50.LoadBitmap(IDB_mana);
		mana_2_51.LoadBitmap(IDB_mana);
		mana_2_52.LoadBitmap(IDB_mana);
		mana_2_53.LoadBitmap(IDB_mana);
		mana_2_54.LoadBitmap(IDB_mana);
		mana_2_55.LoadBitmap(IDB_mana);
		mana_2_56.LoadBitmap(IDB_mana);
		mana_2_57.LoadBitmap(IDB_mana);
		mana_2_58.LoadBitmap(IDB_mana);
		mana_2_59.LoadBitmap(IDB_mana);


		mana_2_6.LoadBitmap(IDB_mana);
		mana_2_60.LoadBitmap(IDB_mana);
		mana_2_61.LoadBitmap(IDB_mana);
		mana_2_62.LoadBitmap(IDB_mana);
		mana_2_63.LoadBitmap(IDB_mana);
		mana_2_64.LoadBitmap(IDB_mana);
		mana_2_65.LoadBitmap(IDB_mana);
		mana_2_66.LoadBitmap(IDB_mana);
		mana_2_67.LoadBitmap(IDB_mana);
		mana_2_68.LoadBitmap(IDB_mana);
		mana_2_69.LoadBitmap(IDB_mana);

		mana_2_7.LoadBitmap(IDB_mana);


		playerA.LoadBitmap();
		playerB.LoadBitmap();

		endA.AddBitmap(IDB_END_A1);
		endA.AddBitmap(IDB_END_A2);

		endB.AddBitmap(IDB_END_B1);
		endB.AddBitmap(IDB_END_B2);


		//
		// 完成部分Loading動作，提高進度
		//
		ShowInitProgress(50);
		Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 繼續載入其他資料
		//
		help.LoadBitmap(IDB_HELP, RGB(255, 255, 255));				// 載入說明的圖形
		corner.LoadBitmap(IDB_CORNER);							// 載入角落圖形
		corner.ShowBitmap(background);							// 將corner貼到background
		bball.LoadBitmap();										// 載入圖形
		hits_left.LoadBitmap();
		//	CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");	// 載入編號0的聲音ding.wav
		//CAudio::Instance()->Load(AUDIO_LAKE, "sounds\\lake.mp3");	// 載入編號1的聲音lake.mp3
		//CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");	// 載入編號2的聲音ntut.mid
		CAudio::Instance()->Load(AUDIO_stage1, "sounds\\stage1.mp3");
		CAudio::Instance()->Load(AUDIO_blade, "sounds\\blade.wav");
		CAudio::Instance()->Load(AUDIO_dart, "sounds\\dart.wav");
		CAudio::Instance()->Load(AUDIO_DUA, "sounds\\DUA.wav");
		CAudio::Instance()->Load(AUDIO_energyball, "sounds\\energyball.wav");
		CAudio::Instance()->Load(AUDIO_energyball2, "sounds\\energyball2.wav");
		CAudio::Instance()->Load(AUDIO_jump, "sounds\\jump.wav");
		CAudio::Instance()->Load(AUDIO_missing, "sounds\\missing.wav");
		CAudio::Instance()->Load(AUDIO_punch, "sounds\\punch.wav");
		CAudio::Instance()->Load(AUDIO_run, "sounds\\run.wav");
		CAudio::Instance()->Load(AUDIO_victory, "sounds\\victory.mp3");
		//
		// 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
		//
	}



	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25;		// keyboard左箭頭
		const char KEY_UP = 0x26;		// keyboard上箭頭
		const char KEY_RIGHT = 0x27;	// keyboard右箭頭
		const char KEY_DOWN = 0x28;		// keyboard下箭頭
		const char KEY_ATTACK = 0x0D;	// keyboard Enter 攻擊
		const char KEY_JUMP = 0x10;		// keyboard shift 跳
		const char KEY_DEFEND = 0x11;	// keyboard ctrl 防禦

		const char KEY_LEFT2 = 0x41;	// keyboard A箭頭 左
		const char KEY_UP2 = 0x57;		// keyboard W箭頭 上
		const char KEY_RIGHT2 = 0x44;	// keyboard D箭頭 右
		const char KEY_DOWN2 = 0x58;	// keyboard X箭頭 下
		const char KEY_ATTACK2 = 0x53;	// keyboard S 攻擊
		const char KEY_JUMP2 = 0x09;	// keyboard tab 跳
		const char KEY_DEFEND2 = 0x34;	// keyboard ` 防禦

		const char KEY_CHEAT = 0x76;	// keyboard F7 回魔回血滿狀態
		const char KEY_moreTool = 0x77;	// keyboard F8 空降道具
		const char KEY_DESTRUCT_TOOL = 0x78; // keyboard F9 道具消失	


		int nowT = I_am_counter;

		if ((B_lastClick == 1 && (nChar == KEY_RIGHT || nChar == KEY_UP || nChar == KEY_DOWN ||
			nChar == KEY_ATTACK || nChar == KEY_JUMP || nChar == KEY_DEFEND)) ||
			(B_lastClick == 2 && (nChar == KEY_LEFT || nChar == KEY_UP || nChar == KEY_DOWN ||
			nChar == KEY_ATTACK || nChar == KEY_JUMP || nChar == KEY_DEFEND))
			){
			playerB.SetRun(false);
		}

		if ((A_lastClick == 1 && (nChar == KEY_RIGHT2 || nChar == KEY_UP2 || nChar == KEY_DOWN2 ||
			nChar == KEY_ATTACK2 || nChar == KEY_JUMP2 || nChar == KEY_DEFEND2)) ||
			(A_lastClick == 2 && (nChar == KEY_LEFT2 || nChar == KEY_UP2 || nChar == KEY_DOWN2 ||
			nChar == KEY_ATTACK2 || nChar == KEY_JUMP2 || nChar == KEY_DEFEND2))
			){
			playerA.SetRun(false);
		}

		if (nChar == KEY_LEFT){
			playerB.SetMovingLeft(true);
			playerB.SetDir(1);

			// 0.33秒(33m*10)內重複按的話就執行
			if (nowT - Last_BLeft < 10 /*&& B_lastClick == 1*/){
				playerB.SetRun(true);
			}

			Last_BLeft = nowT;
			B_lastClick = 1;
		}
		if (nChar == KEY_RIGHT){
			playerB.SetMovingRight(true);
			playerB.SetDir(2);

			if (nowT - Last_BRight < 10){
				playerB.SetRun(true);
			}

			Last_BRight = nowT;
			B_lastClick = 2;
		}
		if (nChar == KEY_UP)
		{
			playerB.SetMovingUp(true);
			B_lastClick = 3;
		}
		if (nChar == KEY_DOWN)
		{
			playerB.SetMovingDown(true);
			B_lastClick = 4;
		}
		if (nChar == KEY_ATTACK){
			playerB.SetAttack(true);
			B_lastClick = 5;
		}
		if (nChar == KEY_JUMP &&
			!((playerB.WhetherJump() == false && playerB.WhetherLand() == true) ||
			(playerB.WhetherJump() == true && playerB.WhetherLand() == false))){
			//上面兩行是避免使用者手賤讓玩家連跳造成當機
			//意思是 跳躍鍵被按下 而且 人物不得 正在往上跳或往下掉
			playerB.SetJump(true);
			playerB.SetOriginalY(playerB.GetY1());
			B_lastClick = 6;
		}

		if (nChar == KEY_DEFEND){
			playerB.SetDefend(true);
			B_lastClick = 7;
		}





		if (nChar == KEY_LEFT2){
			playerA.SetMovingLeft(true);
			playerA.SetDir(1);

			if (nowT - Last_ALeft < 10){
				playerA.SetRun(true);
			}

			Last_ALeft = nowT;
			A_lastClick = 1;
		}
		if (nChar == KEY_RIGHT2){
			playerA.SetMovingRight(true);
			playerA.SetDir(2);

			if (nowT - Last_ARight < 10){
				playerA.SetRun(true);
			}

			Last_ARight = nowT;
			A_lastClick = 2;
		}
		if (nChar == KEY_UP2)
			playerA.SetMovingUp(true);
		if (nChar == KEY_DOWN2)
			playerA.SetMovingDown(true);
		if (nChar == KEY_ATTACK2){
			playerA.SetAttack(true);

			if (playerA.WhetherDLA() || playerA.WhetherDRA()){
				int weaponNum;
				weaponNum = playerA.GetWeaponNumber();
				if (weaponNum < 5) playerA.SetWeaponNumber(weaponNum + 1);
			}
			//else playerA.SetWeaponNumber(1);

		}
		if (nChar == KEY_JUMP2 &&
			!((playerA.WhetherJump() == false && playerA.WhetherLand() == true) ||
			(playerA.WhetherJump() == true && playerA.WhetherLand() == false))){
			//上面兩行是避免使用者手賤讓玩家連跳造成當機
			//意思是 跳躍鍵被按下 而且 人物不得 正在往上跳或往下掉
			playerA.SetJump(true);
			playerA.SetOriginalY(playerA.GetY1());
		}

		if (nChar == KEY_DEFEND2){
			playerA.SetDefend(true);
		}

		if (playerA.WhetherDLA() == false && playerA.WhetherDRA() == false){
			playerA.SetWeaponNumber(1);
		}


		if (nChar == KEY_CHEAT){
			int b1, m1, b2, m2;
			b1 = playerA.Getb1();
			m1 = playerA.Getm1();
			b2 = playerB.Getb2();
			m2 = playerB.Getm2();

			playerA.Setb1(66 - b1);
			playerA.Setm1(66 - m1);
			playerB.Setb2(66 - b2);
			playerB.Setm2(66 - m2);
		}

		if (nChar == KEY_moreTool){
			firstTool++;
			if (firstTool == 1)tool1A.SetShow(true, firstTool);
			else if (firstTool == 2)
				tool1B.SetShow(true, firstTool);
			else if (firstTool == 3)tool1C.SetShow(true, firstTool);
			else if (firstTool == 4)tool2A.SetShow(true, firstTool);
			else if (firstTool == 5)tool2B.SetShow(true, firstTool);
			else if (firstTool == 6)tool2C.SetShow(true, firstTool);
			else if (firstTool == 7)tool3A.SetShow(true, firstTool);
			else if (firstTool == 8)tool3B.SetShow(true, firstTool);
			else if (firstTool == 9)tool3C.SetShow(true, firstTool);

		}

		///////////////////// 道具撿拾事件判定 /////////////////////

		if (nChar == KEY_ATTACK2 && tool1A.GetVisible()){
			if ((tool1A.GetTool1X() - playerA.GetX1() <= 40) && (tool1A.GetTool1X() - playerA.GetX1() >= -40) &&
				(tool1A.GetTool1Y() - (playerA.GetY1() + 135) <= 75) && (tool1A.GetTool1Y() - (playerA.GetY1() + 135) >= -25)) {
				//符合判斷式應該算是多少有碰到道具了
				tool1A.A_Take1(true);
			}
			else if ((tool1A.GetTool2X() - playerA.GetX1() <= 40) && (tool1A.GetTool2X() - playerA.GetX1() >= -40) &&
				(tool1A.GetTool2Y() - (playerA.GetY1() + 135) <= 75) && (tool1A.GetTool2Y() - (playerA.GetY1() + 135) >= -25)) {
				tool1A.A_Take2(true);
			}

		}

		if (nChar == KEY_ATTACK && tool1A.GetVisible()){
			if ((tool1A.GetTool1X() - playerB.GetX1() <= 40) && (tool1A.GetTool1X() - playerB.GetX1() >= -40) &&
				(tool1A.GetTool1Y() - (playerB.GetY1() + 135) <= 75) && (tool1A.GetTool1Y() - (playerB.GetY1() + 135) >= -25)) {
				//符合判斷式應該算是多少有碰到道具了
				tool1A.B_Take1(true);
				playerB.SetTool(true);
			}
			else if ((tool1A.GetTool2X() - playerB.GetX1() <= 40) && (tool1A.GetTool2X() - playerB.GetX1() >= -40) &&
				(tool1A.GetTool2Y() - (playerB.GetY1() + 135) <= 75) && (tool1A.GetTool2Y() - (playerB.GetY1() + 135) >= -25)) {
				tool1A.B_Take2(true);
				playerB.SetTool(true);
			}
		}



		if (nChar == KEY_DESTRUCT_TOOL){
			tool1A.Initialize();
			playerA.SetTool(false);
			playerB.SetTool(false);
			tool1B.Initialize();
			tool1C.Initialize();
			tool2A.Initialize();
			tool2B.Initialize();
			tool2C.Initialize();
			tool3A.Initialize();
			tool3B.Initialize();
			tool3C.Initialize();
			firstTool = 0;
		}


	}
	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25;		// keyboard左箭頭
		const char KEY_UP = 0x26;		// keyboard上箭頭
		const char KEY_RIGHT = 0x27;	// keyboard右箭頭
		const char KEY_DOWN = 0x28;		// keyboard下箭頭
		const char KEY_ATTACK = 0x0D;	// keyboard Enter 攻擊
		const char KEY_JUMP = 0x10;		// keyboard shift 跳
		const char KEY_DEFEND = 0x11;	// keyboard ctrl 防禦

		const char KEY_LEFT2 = 0x41;	// keyboard A箭頭 左
		const char KEY_UP2 = 0x57;		// keyboard W箭頭 上
		const char KEY_RIGHT2 = 0x44;	// keyboard D箭頭 右
		const char KEY_DOWN2 = 0x58;	// keyboard X箭頭 下
		const char KEY_ATTACK2 = 0x53;	// keyboard S 攻擊
		const char KEY_JUMP2 = 0x09;	// keyboard tab 跳
		const char KEY_DEFEND2 = 0x34;	// keyboard ` 防禦

		//const char KEY_moreTool = 0x42;	// keyboard F8 空降道具
		const char KEY_moreTool = 0x20;	// keyboard space 空降道具 test

		if (nChar == KEY_LEFT)
			playerB.SetMovingLeft(false);
		if (nChar == KEY_RIGHT)
			playerB.SetMovingRight(false);
		if (nChar == KEY_UP)
			playerB.SetMovingUp(false);
		if (nChar == KEY_DOWN)
			playerB.SetMovingDown(false);
		if (nChar == KEY_ATTACK){
			Sleep(110);//在放開攻擊鍵之後稍作延遲,才不會因圖片顯示太快看起來像抽搐
			playerB.SetAttack(false);
		}
		if (nChar == KEY_DEFEND){
			Sleep(150);
			playerB.SetDefend(false);
		}


		if (nChar == KEY_LEFT2)
			playerA.SetMovingLeft(false);
		if (nChar == KEY_RIGHT2)
			playerA.SetMovingRight(false);
		if (nChar == KEY_UP2)
			playerA.SetMovingUp(false);
		if (nChar == KEY_DOWN2)
			playerA.SetMovingDown(false);
		if (nChar == KEY_ATTACK2)
		{
			Sleep(100);//在放開攻擊鍵之後稍作延遲,才不會因圖片顯示太快看起來像抽搐
			playerA.SetAttack(false);
		}
		if (nChar == KEY_DEFEND2){
			Sleep(150);
			playerA.SetDefend(false);
		}
		if (nChar == KEY_moreTool){

		}
	}



	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
	{
		eraser.SetMovingLeft(true);

	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
		eraser.SetMovingLeft(false);
	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
		// 沒事。如果需要處理滑鼠移動的話，寫code在這裡

	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
	{
		eraser.SetMovingRight(true);
	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
		eraser.SetMovingRight(false);
	}
	void CGameStateRun::OnShow()
	{
		//
		//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
		//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
		//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。
		//
		//
		//  貼上背景圖、撞擊數、球、擦子、彈跳的球
		//


		background.ShowBitmap();			// 貼上背景圖

		bar.ShowBitmap();

		playerA_logo.ShowBitmap();
		playerB_logo.ShowBitmap();
		//////////////////////////////////////////



		//////////////////////////////////////////////

		help.ShowBitmap();					// 貼上說明圖
		hits_left.ShowBitmap();
		playerA.OnShow();
		playerB.OnShow();
		//
		//  貼上左上及右下角落的圖
		//
		corner.SetTopLeft(0, 0);
		corner.ShowBitmap();
		corner.SetTopLeft(SIZE_X - corner.Width(), SIZE_Y - corner.Height());
		corner.ShowBitmap();



		//test 抓時間
		I_am_counter++;



		tool1A.OnShow();
		tool1B.OnShow();
		tool1C.OnShow();
		tool2A.OnShow();
		tool2B.OnShow();
		tool2C.OnShow();
		tool3A.OnShow();
		tool3B.OnShow();
		tool3C.OnShow();



		////////////////////////////////////////// 以下皆為血量判定與顯示







		///////////////////////////////////////////////////////////////////

		if (playerA.Getb1() > 0)
			blood1.ShowBitmap();
		if (playerA.Getb1() > 1)
			blood10.ShowBitmap();
		if (playerA.Getb1() > 2)
			blood11.ShowBitmap();
		if (playerA.Getb1() > 3)
			blood12.ShowBitmap();
		if (playerA.Getb1() > 4)
			blood13.ShowBitmap();
		if (playerA.Getb1() > 5)
			blood14.ShowBitmap();
		if (playerA.Getb1() > 6)
			blood15.ShowBitmap();
		if (playerA.Getb1() > 7)
			blood16.ShowBitmap();
		if (playerA.Getb1() > 8)
			blood17.ShowBitmap();
		if (playerA.Getb1() > 9)
			blood18.ShowBitmap();
		if (playerA.Getb1() > 10)
			blood19.ShowBitmap();

		if (playerA.Getb1() > 11)
			blood2.ShowBitmap();
		if (playerA.Getb1() > 12)
			blood20.ShowBitmap();
		if (playerA.Getb1() > 13)
			blood21.ShowBitmap();
		if (playerA.Getb1() > 14)
			blood22.ShowBitmap();
		if (playerA.Getb1() > 15)
			blood23.ShowBitmap();
		if (playerA.Getb1() > 16)
			blood24.ShowBitmap();
		if (playerA.Getb1() > 17)
			blood25.ShowBitmap();
		if (playerA.Getb1() > 18)
			blood26.ShowBitmap();
		if (playerA.Getb1() > 19)
			blood27.ShowBitmap();
		if (playerA.Getb1() > 20)
			blood28.ShowBitmap();
		if (playerA.Getb1() > 21)
			blood29.ShowBitmap();

		if (playerA.Getb1() > 22)
			blood3.ShowBitmap();
		if (playerA.Getb1() > 23)
			blood30.ShowBitmap();
		if (playerA.Getb1() > 24)
			blood31.ShowBitmap();
		if (playerA.Getb1() > 25)
			blood32.ShowBitmap();
		if (playerA.Getb1() > 26)
			blood33.ShowBitmap();
		if (playerA.Getb1() > 27)
			blood34.ShowBitmap();
		if (playerA.Getb1() > 28)
			blood35.ShowBitmap();
		if (playerA.Getb1() > 29)
			blood36.ShowBitmap();
		if (playerA.Getb1() > 30)
			blood37.ShowBitmap();
		if (playerA.Getb1() > 31)
			blood38.ShowBitmap();
		if (playerA.Getb1() > 32)
			blood39.ShowBitmap();

		if (playerA.Getb1() > 33)
			blood4.ShowBitmap();
		if (playerA.Getb1() > 34)
			blood40.ShowBitmap();
		if (playerA.Getb1() > 35)
			blood41.ShowBitmap();
		if (playerA.Getb1() > 36)
			blood42.ShowBitmap();
		if (playerA.Getb1() > 37)
			blood43.ShowBitmap();
		if (playerA.Getb1() > 38)
			blood44.ShowBitmap();
		if (playerA.Getb1() > 39)
			blood45.ShowBitmap();
		if (playerA.Getb1() > 40)
			blood46.ShowBitmap();
		if (playerA.Getb1() > 41)
			blood47.ShowBitmap();
		if (playerA.Getb1() > 42)
			blood48.ShowBitmap();
		if (playerA.Getb1() > 43)
			blood49.ShowBitmap();

		if (playerA.Getb1() > 44)
			blood5.ShowBitmap();
		if (playerA.Getb1() > 45)
			blood50.ShowBitmap();
		if (playerA.Getb1() > 46)
			blood51.ShowBitmap();
		if (playerA.Getb1() > 47)
			blood52.ShowBitmap();
		if (playerA.Getb1() > 48)
			blood53.ShowBitmap();
		if (playerA.Getb1() > 49)
			blood54.ShowBitmap();
		if (playerA.Getb1() > 50)
			blood55.ShowBitmap();
		if (playerA.Getb1() > 51)
			blood56.ShowBitmap();
		if (playerA.Getb1() > 52)
			blood57.ShowBitmap();
		if (playerA.Getb1() > 53)
			blood58.ShowBitmap();
		if (playerA.Getb1() > 54)
			blood59.ShowBitmap();


		if (playerA.Getb1() > 55)
			blood6.ShowBitmap();
		if (playerA.Getb1() > 56)
			blood60.ShowBitmap();
		if (playerA.Getb1() > 57)
			blood61.ShowBitmap();
		if (playerA.Getb1() > 58)
			blood62.ShowBitmap();
		if (playerA.Getb1() > 59)
			blood63.ShowBitmap();
		if (playerA.Getb1() > 60)
			blood64.ShowBitmap();
		if (playerA.Getb1() > 61)
			blood65.ShowBitmap();
		if (playerA.Getb1() > 62)
			blood66.ShowBitmap();
		if (playerA.Getb1() > 63)
			blood67.ShowBitmap();
		if (playerA.Getb1() > 64)
			blood68.ShowBitmap();
		if (playerA.Getb1() > 65)
			blood69.ShowBitmap();


		//////////////////////////////////////////////


		if (playerB.Getb2() > 0)
			blood_2_1.ShowBitmap();
		if (playerB.Getb2() > 1)
			blood_2_10.ShowBitmap();
		if (playerB.Getb2() > 2)
			blood_2_11.ShowBitmap();
		if (playerB.Getb2() > 3)
			blood_2_12.ShowBitmap();
		if (playerB.Getb2() > 4)
			blood_2_13.ShowBitmap();
		if (playerB.Getb2() > 5)
			blood_2_14.ShowBitmap();
		if (playerB.Getb2() > 6)
			blood_2_15.ShowBitmap();
		if (playerB.Getb2() > 7)
			blood_2_16.ShowBitmap();
		if (playerB.Getb2() > 8)
			blood_2_17.ShowBitmap();
		if (playerB.Getb2() > 9)
			blood_2_18.ShowBitmap();
		if (playerB.Getb2() > 10)
			blood_2_19.ShowBitmap();

		if (playerB.Getb2() > 11)
			blood_2_2.ShowBitmap();
		if (playerB.Getb2() > 12)
			blood_2_20.ShowBitmap();
		if (playerB.Getb2() > 13)
			blood_2_21.ShowBitmap();
		if (playerB.Getb2() > 14)
			blood_2_22.ShowBitmap();
		if (playerB.Getb2() > 15)
			blood_2_23.ShowBitmap();
		if (playerB.Getb2() > 16)
			blood_2_24.ShowBitmap();
		if (playerB.Getb2() > 17)
			blood_2_25.ShowBitmap();
		if (playerB.Getb2() > 18)
			blood_2_26.ShowBitmap();
		if (playerB.Getb2() > 19)
			blood_2_27.ShowBitmap();
		if (playerB.Getb2() > 20)
			blood_2_28.ShowBitmap();
		if (playerB.Getb2() > 21)
			blood_2_29.ShowBitmap();

		if (playerB.Getb2() > 22)
			blood_2_3.ShowBitmap();
		if (playerB.Getb2() > 23)
			blood_2_30.ShowBitmap();
		if (playerB.Getb2() > 24)
			blood_2_31.ShowBitmap();
		if (playerB.Getb2() > 25)
			blood_2_32.ShowBitmap();
		if (playerB.Getb2() > 26)
			blood_2_33.ShowBitmap();
		if (playerB.Getb2() > 27)
			blood_2_34.ShowBitmap();
		if (playerB.Getb2() > 28)
			blood_2_35.ShowBitmap();
		if (playerB.Getb2() > 29)
			blood_2_36.ShowBitmap();
		if (playerB.Getb2() > 30)
			blood_2_37.ShowBitmap();
		if (playerB.Getb2() > 31)
			blood_2_38.ShowBitmap();
		if (playerB.Getb2() > 32)
			blood_2_39.ShowBitmap();

		if (playerB.Getb2() > 33)
			blood_2_4.ShowBitmap();
		if (playerB.Getb2() > 34)
			blood_2_40.ShowBitmap();
		if (playerB.Getb2() > 35)
			blood_2_41.ShowBitmap();
		if (playerB.Getb2() > 36)
			blood_2_42.ShowBitmap();
		if (playerB.Getb2() > 37)
			blood_2_43.ShowBitmap();
		if (playerB.Getb2() > 38)
			blood_2_44.ShowBitmap();
		if (playerB.Getb2() > 39)
			blood_2_45.ShowBitmap();
		if (playerB.Getb2() > 40)
			blood_2_46.ShowBitmap();
		if (playerB.Getb2() > 41)
			blood_2_47.ShowBitmap();
		if (playerB.Getb2() > 42)
			blood_2_48.ShowBitmap();
		if (playerB.Getb2() > 43)
			blood_2_49.ShowBitmap();

		if (playerB.Getb2() > 44)
			blood_2_5.ShowBitmap();
		if (playerB.Getb2() > 45)
			blood_2_50.ShowBitmap();
		if (playerB.Getb2() > 46)
			blood_2_51.ShowBitmap();
		if (playerB.Getb2() > 47)
			blood_2_52.ShowBitmap();
		if (playerB.Getb2() > 48)
			blood_2_53.ShowBitmap();
		if (playerB.Getb2() > 49)
			blood_2_54.ShowBitmap();
		if (playerB.Getb2() > 50)
			blood_2_55.ShowBitmap();
		if (playerB.Getb2() > 51)
			blood_2_56.ShowBitmap();
		if (playerB.Getb2() > 52)
			blood_2_57.ShowBitmap();
		if (playerB.Getb2() > 53)
			blood_2_58.ShowBitmap();
		if (playerB.Getb2() > 54)
			blood_2_59.ShowBitmap();


		if (playerB.Getb2() > 55)
			blood_2_6.ShowBitmap();
		if (playerB.Getb2() > 56)
			blood_2_60.ShowBitmap();
		if (playerB.Getb2() > 57)
			blood_2_61.ShowBitmap();
		if (playerB.Getb2() > 58)
			blood_2_62.ShowBitmap();
		if (playerB.Getb2() > 59)
			blood_2_63.ShowBitmap();
		if (playerB.Getb2() > 60)
			blood_2_64.ShowBitmap();
		if (playerB.Getb2() > 61)
			blood_2_65.ShowBitmap();
		if (playerB.Getb2() > 62)
			blood_2_66.ShowBitmap();
		if (playerB.Getb2() > 63)
			blood_2_67.ShowBitmap();
		if (playerB.Getb2() > 64)
			blood_2_68.ShowBitmap();
		if (playerB.Getb2() > 65)
			blood_2_69.ShowBitmap();

		////////////////////////////////////////////

		if (playerA.Getm1() > 0)
			mana1.ShowBitmap();
		if (playerA.Getm1() > 1)
			mana10.ShowBitmap();
		if (playerA.Getm1() > 2)
			mana11.ShowBitmap();
		if (playerA.Getm1() > 3)
			mana12.ShowBitmap();
		if (playerA.Getm1() > 4)
			mana13.ShowBitmap();
		if (playerA.Getm1() > 5)
			mana14.ShowBitmap();
		if (playerA.Getm1() > 6)
			mana15.ShowBitmap();
		if (playerA.Getm1() > 7)
			mana16.ShowBitmap();
		if (playerA.Getm1() > 8)
			mana17.ShowBitmap();
		if (playerA.Getm1() > 9)
			mana18.ShowBitmap();
		if (playerA.Getm1() > 10)
			mana19.ShowBitmap();

		if (playerA.Getm1() > 11)
			mana2.ShowBitmap();
		if (playerA.Getm1() > 12)
			mana20.ShowBitmap();
		if (playerA.Getm1() > 13)
			mana21.ShowBitmap();
		if (playerA.Getm1() > 14)
			mana22.ShowBitmap();
		if (playerA.Getm1() > 15)
			mana23.ShowBitmap();
		if (playerA.Getm1() > 16)
			mana24.ShowBitmap();
		if (playerA.Getm1() > 17)
			mana25.ShowBitmap();
		if (playerA.Getm1() > 18)
			mana26.ShowBitmap();
		if (playerA.Getm1() > 19)
			mana27.ShowBitmap();
		if (playerA.Getm1() > 20)
			mana28.ShowBitmap();
		if (playerA.Getm1() > 21)
			mana29.ShowBitmap();

		if (playerA.Getm1() > 22)
			mana3.ShowBitmap();
		if (playerA.Getm1() > 23)
			mana30.ShowBitmap();
		if (playerA.Getm1() > 24)
			mana31.ShowBitmap();
		if (playerA.Getm1() > 25)
			mana32.ShowBitmap();
		if (playerA.Getm1() > 26)
			mana33.ShowBitmap();
		if (playerA.Getm1() > 27)
			mana34.ShowBitmap();
		if (playerA.Getm1() > 28)
			mana35.ShowBitmap();
		if (playerA.Getm1() > 29)
			mana36.ShowBitmap();
		if (playerA.Getm1() > 30)
			mana37.ShowBitmap();
		if (playerA.Getm1() > 31)
			mana38.ShowBitmap();
		if (playerA.Getm1() > 32)
			mana39.ShowBitmap();

		if (playerA.Getm1() > 33)
			mana4.ShowBitmap();
		if (playerA.Getm1() > 34)
			mana40.ShowBitmap();
		if (playerA.Getm1() > 35)
			mana41.ShowBitmap();
		if (playerA.Getm1() > 36)
			mana42.ShowBitmap();
		if (playerA.Getm1() > 37)
			mana43.ShowBitmap();
		if (playerA.Getm1() > 38)
			mana44.ShowBitmap();
		if (playerA.Getm1() > 39)
			mana45.ShowBitmap();
		if (playerA.Getm1() > 40)
			mana46.ShowBitmap();
		if (playerA.Getm1() > 41)
			mana47.ShowBitmap();
		if (playerA.Getm1() > 42)
			mana48.ShowBitmap();
		if (playerA.Getm1() > 43)
			mana49.ShowBitmap();

		if (playerA.Getm1() > 44)
			mana5.ShowBitmap();
		if (playerA.Getm1() > 45)
			mana50.ShowBitmap();
		if (playerA.Getm1() > 46)
			mana51.ShowBitmap();
		if (playerA.Getm1() > 47)
			mana52.ShowBitmap();
		if (playerA.Getm1() > 48)
			mana53.ShowBitmap();
		if (playerA.Getm1() > 49)
			mana54.ShowBitmap();
		if (playerA.Getm1() > 50)
			mana55.ShowBitmap();
		if (playerA.Getm1() > 51)
			mana56.ShowBitmap();
		if (playerA.Getm1() > 52)
			mana57.ShowBitmap();
		if (playerA.Getm1() > 53)
			mana58.ShowBitmap();
		if (playerA.Getm1() > 54)
			mana59.ShowBitmap();


		if (playerA.Getm1() > 55)
			mana6.ShowBitmap();
		if (playerA.Getm1() > 56)
			mana60.ShowBitmap();
		if (playerA.Getm1() > 57)
			mana61.ShowBitmap();
		if (playerA.Getm1() > 58)
			mana62.ShowBitmap();
		if (playerA.Getm1() > 59)
			mana63.ShowBitmap();
		if (playerA.Getm1() > 60)
			mana64.ShowBitmap();
		if (playerA.Getm1() > 61)
			mana65.ShowBitmap();
		if (playerA.Getm1() > 62)
			mana66.ShowBitmap();
		if (playerA.Getm1() > 63)
			mana67.ShowBitmap();
		if (playerA.Getm1() > 64)
			mana68.ShowBitmap();
		if (playerA.Getm1() > 65)
			mana69.ShowBitmap();

		////////////////////////////////////////////

		if (playerB.Getm2() > 0)
			mana_2_1.ShowBitmap();
		if (playerB.Getm2() > 1)
			mana_2_10.ShowBitmap();
		if (playerB.Getm2() > 2)
			mana_2_11.ShowBitmap();
		if (playerB.Getm2() > 3)
			mana_2_12.ShowBitmap();
		if (playerB.Getm2() > 4)
			mana_2_13.ShowBitmap();
		if (playerB.Getm2() > 5)
			mana_2_14.ShowBitmap();
		if (playerB.Getm2() > 6)
			mana_2_15.ShowBitmap();
		if (playerB.Getm2() > 7)
			mana_2_16.ShowBitmap();
		if (playerB.Getm2() > 8)
			mana_2_17.ShowBitmap();
		if (playerB.Getm2() > 9)
			mana_2_18.ShowBitmap();
		if (playerB.Getm2() > 10)
			mana_2_19.ShowBitmap();

		if (playerB.Getm2() > 11)
			mana_2_2.ShowBitmap();
		if (playerB.Getm2() > 12)
			mana_2_20.ShowBitmap();
		if (playerB.Getm2() > 13)
			mana_2_21.ShowBitmap();
		if (playerB.Getm2() > 14)
			mana_2_22.ShowBitmap();
		if (playerB.Getm2() > 15)
			mana_2_23.ShowBitmap();
		if (playerB.Getm2() > 16)
			mana_2_24.ShowBitmap();
		if (playerB.Getm2() > 17)
			mana_2_25.ShowBitmap();
		if (playerB.Getm2() > 18)
			mana_2_26.ShowBitmap();
		if (playerB.Getm2() > 19)
			mana_2_27.ShowBitmap();
		if (playerB.Getm2() > 20)
			mana_2_28.ShowBitmap();
		if (playerB.Getm2() > 21)
			mana_2_29.ShowBitmap();

		if (playerB.Getm2() > 22)
			mana_2_3.ShowBitmap();
		if (playerB.Getm2() > 23)
			mana_2_30.ShowBitmap();
		if (playerB.Getm2() > 24)
			mana_2_31.ShowBitmap();
		if (playerB.Getm2() > 25)
			mana_2_32.ShowBitmap();
		if (playerB.Getm2() > 26)
			mana_2_33.ShowBitmap();
		if (playerB.Getm2() > 27)
			mana_2_34.ShowBitmap();
		if (playerB.Getm2() > 28)
			mana_2_35.ShowBitmap();
		if (playerB.Getm2() > 29)
			mana_2_36.ShowBitmap();
		if (playerB.Getm2() > 30)
			mana_2_37.ShowBitmap();
		if (playerB.Getm2() > 31)
			mana_2_38.ShowBitmap();
		if (playerB.Getm2() > 32)
			mana_2_39.ShowBitmap();

		if (playerB.Getm2() > 33)
			mana_2_4.ShowBitmap();
		if (playerB.Getm2() > 34)
			mana_2_40.ShowBitmap();
		if (playerB.Getm2() > 35)
			mana_2_41.ShowBitmap();
		if (playerB.Getm2() > 36)
			mana_2_42.ShowBitmap();
		if (playerB.Getm2() > 37)
			mana_2_43.ShowBitmap();
		if (playerB.Getm2() > 38)
			mana_2_44.ShowBitmap();
		if (playerB.Getm2() > 39)
			mana_2_45.ShowBitmap();
		if (playerB.Getm2() > 40)
			mana_2_46.ShowBitmap();
		if (playerB.Getm2() > 41)
			mana_2_47.ShowBitmap();
		if (playerB.Getm2() > 42)
			mana_2_48.ShowBitmap();
		if (playerB.Getm2() > 43)
			mana_2_49.ShowBitmap();

		if (playerB.Getm2() > 44)
			mana_2_5.ShowBitmap();
		if (playerB.Getm2() > 45)
			mana_2_50.ShowBitmap();
		if (playerB.Getm2() > 46)
			mana_2_51.ShowBitmap();
		if (playerB.Getm2() > 47)
			mana_2_52.ShowBitmap();
		if (playerB.Getm2() > 48)
			mana_2_53.ShowBitmap();
		if (playerB.Getm2() > 49)
			mana_2_54.ShowBitmap();
		if (playerB.Getm2() > 50)
			mana_2_55.ShowBitmap();
		if (playerB.Getm2() > 51)
			mana_2_56.ShowBitmap();
		if (playerB.Getm2() > 52)
			mana_2_57.ShowBitmap();
		if (playerB.Getm2() > 53)
			mana_2_58.ShowBitmap();
		if (playerB.Getm2() > 54)
			mana_2_59.ShowBitmap();


		if (playerB.Getm2() > 55)
			mana_2_6.ShowBitmap();
		if (playerB.Getm2() > 56)
			mana_2_60.ShowBitmap();
		if (playerB.Getm2() > 57)
			mana_2_61.ShowBitmap();
		if (playerB.Getm2() > 58)
			mana_2_62.ShowBitmap();
		if (playerB.Getm2() > 59)
			mana_2_63.ShowBitmap();
		if (playerB.Getm2() > 60)
			mana_2_64.ShowBitmap();
		if (playerB.Getm2() > 61)
			mana_2_65.ShowBitmap();
		if (playerB.Getm2() > 62)
			mana_2_66.ShowBitmap();
		if (playerB.Getm2() > 63)
			mana_2_67.ShowBitmap();
		if (playerB.Getm2() > 64)
			mana_2_68.ShowBitmap();
		if (playerB.Getm2() > 65)
			mana_2_69.ShowBitmap();

		//////////////////////////////////////////////

		if (playerB.Getb2() < 1){
			endA.OnShow();
			playerA.Setm1(0);
			playerB.Setm2(0);
			CAudio::Instance()->Stop(AUDIO_blade);
			CAudio::Instance()->Stop(AUDIO_dart);
			CAudio::Instance()->Stop(AUDIO_DUA);
			CAudio::Instance()->Stop(AUDIO_energyball2);
			CAudio::Instance()->Stop(AUDIO_jump);
			CAudio::Instance()->Stop(AUDIO_energyball);
			CAudio::Instance()->Stop(AUDIO_missing);
			CAudio::Instance()->Stop(AUDIO_punch);
			CAudio::Instance()->Stop(AUDIO_run);



		}
		if (playerA.Getb1() < 1){
			endB.OnShow();
			playerA.Setm1(0);
			playerB.Setm2(0);
			CAudio::Instance()->Stop(AUDIO_blade);
			CAudio::Instance()->Stop(AUDIO_dart);
			CAudio::Instance()->Stop(AUDIO_DUA);
			CAudio::Instance()->Stop(AUDIO_energyball2);
			CAudio::Instance()->Stop(AUDIO_jump);
			CAudio::Instance()->Stop(AUDIO_energyball);
			CAudio::Instance()->Stop(AUDIO_missing);
			CAudio::Instance()->Stop(AUDIO_punch);
			CAudio::Instance()->Stop(AUDIO_run);
		}
	} //for -> OnShow() 
}
