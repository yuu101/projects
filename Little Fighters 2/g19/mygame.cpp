
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
namespace game_framework
{

	/////////////////////////////////////////////////////////////////////////////
	// CBall: Ball class
	/////////////////////////////////////////////////////////////////////////////

	CBall::CBall()
	{
		is_alive = true;
		x = y = dx = dy = index = delay_counter = 0;
	}

	bool CBall::HitEraser(CEraser* eraser)
	{
		// 檢測擦子所構成的矩形是否碰到球
		return HitRectangle(eraser->GetX1(), eraser->GetY1(),
			eraser->GetX2(), eraser->GetY2());
	}

	bool CBall::HitRectangle(int tx1, int ty1, int tx2, int ty2)
	{
		int x1 = x + dx;				// 球的左上角x座標
		int y1 = y + dy;				// 球的左上角y座標
		int x2 = x1 + bmp.Width();	// 球的右下角x座標
		int y2 = y1 + bmp.Height();	// 球的右下角y座標
		//
		// 檢測球的矩形與參數矩形是否有交集
		//
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	bool CBall::IsAlive()
	{
		return is_alive;
	}

	void CBall::LoadBitmap()
	{
		bmp.LoadBitmap(IDB_BALL, RGB(0, 0, 0));			// 載入球的圖形
		bmp_center.LoadBitmap(IDB_CENTER, RGB(0, 0, 0));	// 載入球圓心的圖形

	}

	void CBall::OnMove()
	{
		if (!is_alive)
			return;
		delay_counter--;
		if (delay_counter < 0)
		{
			delay_counter = delay;
			//
			// 計算球向對於圓心的位移量dx, dy
			//
			const int STEPS = 18;
			static const int DIFFX[] = { 35, 32, 26, 17, 6, -6, -17, -26, -32, -34, -32, -26, -17, -6, 6, 17, 26, 32, };
			static const int DIFFY[] = { 0, 11, 22, 30, 34, 34, 30, 22, 11, 0, -11, -22, -30, -34, -34, -30, -22, -11, };
			index++;
			if (index >= STEPS)
				index = 0;
			dx = DIFFX[index];
			dy = DIFFY[index];
		}
	}

	void CBall::SetDelay(int d)
	{
		delay = d;
	}

	void CBall::SetIsAlive(bool alive)
	{
		is_alive = alive;
	}

	void CBall::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	void CBall::OnShow()
	{
		if (is_alive)
		{
			bmp.SetTopLeft(x + dx, y + dy);
			bmp.ShowBitmap();
			bmp_center.SetTopLeft(x, y);
			bmp_center.ShowBitmap();
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// CBouncingBall: BouncingBall class
	/////////////////////////////////////////////////////////////////////////////

	CBouncingBall::CBouncingBall()
	{
		const int INITIAL_VELOCITY = 20;	// 初始上升速度
		const int FLOOR = 400;				// 地板座標
		floor = FLOOR;
		x = 95;
		y = FLOOR - 1;				// y座標比地板高1點(站在地板上)
		rising = true;
		initial_velocity = INITIAL_VELOCITY;
		velocity = initial_velocity;
	}

	void CBouncingBall::LoadBitmap()
	{
		char* filename[4] = { ".\\bitmaps\\ball1.bmp", ".\\bitmaps\\ball2.bmp", ".\\bitmaps\\ball3.bmp", ".\\bitmaps\\ball4.bmp" };
		for (int i = 0; i < 4; i++)	// 載入動畫(由4張圖形構成)
			animation.AddBitmap(filename[i], RGB(0, 0, 0));
	}

	void CBouncingBall::OnMove()
	{
		if (rising)  			// 上升狀態
		{
			if (velocity > 0)
			{
				y -= velocity;	// 當速度 > 0時，y軸上升(移動velocity個點，velocity的單位為 點/次)
				velocity--;		// 受重力影響，下次的上升速度降低
			}
			else
			{
				rising = false; // 當速度 <= 0，上升終止，下次改為下降
				velocity = 1;	// 下降的初速(velocity)為1
			}
		}
		else  				// 下降狀態
		{
			if (y < floor - 1)  // 當y座標還沒碰到地板
			{
				y += velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)
				velocity++;		// 受重力影響，下次的下降速度增加
			}
			else
			{
				y = floor - 1;  // 當y座標低於地板，更正為地板上
				rising = true;	// 探底反彈，下次改為上升
				velocity = initial_velocity; // 重設上升初始速度
			}
		}
		animation.OnMove();		// 執行一次animation.OnMove()，animation才會換圖
	}

	void CBouncingBall::OnShow()
	{
		animation.SetTopLeft(x, y);
		animation.OnShow();
	}

	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CEraser::CEraser()
	{
		Initialize();
	}

	int CEraser::GetX1()
	{
		return x;
	}

	int CEraser::GetY1()
	{
		return y;
	}

	int CEraser::GetX2()
	{
		return x + animation.Width();
	}

	int CEraser::GetY2()
	{
		return y + animation.Height();
	}

	void CEraser::Initialize()
	{
		const int X_POS = 280;
		const int Y_POS = 400;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void CEraser::LoadBitmap()
	{
		animation.AddBitmap(IDB_ERASER1, RGB(255, 255, 255));
		animation.AddBitmap(IDB_ERASER2, RGB(255, 255, 255));
		animation.AddBitmap(IDB_ERASER3, RGB(255, 255, 255));
		animation.AddBitmap(IDB_ERASER2, RGB(255, 255, 255));

	}

	void CEraser::OnMove()
	{
		const int STEP_SIZE = 2;
		animation.OnMove();
		if (isMovingLeft)
			x -= STEP_SIZE;
		if (isMovingRight)
			x += STEP_SIZE;
		if (isMovingUp)
			y -= STEP_SIZE;
		if (isMovingDown)
			y += STEP_SIZE;
	}

	void CEraser::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CEraser::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CEraser::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CEraser::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CEraser::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	void CEraser::OnShow()
	{
		animation.SetTopLeft(x, y);
		animation.OnShow();
	}

	//////////////////////////////////正式程式////////////////////////////////// 

	CWeapon::CWeapon(){
		Initialize();
	}

	void CWeapon::Initialize(){

	}
	void CWeapon::LoadBitmap(){
		test_weapon.AddBitmap(IDB_test_weapon, RGB(255, 255, 255));
	}








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

	int CPlayerA::GetWeaponY(){
		return weaponY - 90;
	}

	bool CPlayerA::WhetherJump(){
		return isJump;
	}

	bool CPlayerA::WhetherLand(){
		return isLand;
	}

	void CPlayerA::Initialize()
	{
		const int X_POS = 300;
		const int Y_POS = 240;
		b1 = 66;
		m1 = 66;
		counter1 = counter2 = counter3 = counter4 = 0;
		x = X_POS;
		y = Y_POS;
		dir = 2;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isAttack = weaponing = isJump = isLand = isDefend = false;
	}



	void CPlayerA::LoadBitmap()
	{
		playerA_pic1.AddBitmap(IDB_playerA_2, RGB(255, 255, 255));
		playerA_pic2.AddBitmap(IDB_playerA, RGB(255, 255, 255));

		attackA_L.AddBitmap(IDB_AttackAL, RGB(255, 255, 255));
		attackA_R.AddBitmap(IDB_AttackAR, RGB(255, 255, 255));

		weapon.AddBitmap(IDB_Bweapon, RGB(255, 255, 255));

		jumpA_L.AddBitmap(IDB_jumpA_L, RGB(255, 255, 255));
		jumpA_R.AddBitmap(IDB_jumpA_R, RGB(255, 255, 255));

		defendA_L.AddBitmap(IDB_defendA_L, RGB(255, 255, 255));
		defendA_R.AddBitmap(IDB_defendA_R, RGB(255, 255, 255));

		runA_L.AddBitmap(IDB_runA_L, RGB(255, 255, 255));
		runA_R.AddBitmap(IDB_runA_R, RGB(255, 255, 255));
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

	void CPlayerA::OnMove()
	{
		const int STEP_SIZE = 4;

		if (isMovingLeft&&x >= 0)
			x -= STEP_SIZE;
		if (isMovingRight&&x <= 760)
			x += STEP_SIZE;
		if (isMovingUp&&y >= 150)
			y -= STEP_SIZE;
		if (isMovingDown&&y <= 350)
			y += STEP_SIZE;

		///////////////////////此段為撰寫虛擬武器/////////////////////////////

		weapon.SetTopLeft(x - 12, y + 135);
		attackA_L.SetTopLeft(x - 40, y + 135);
		attackA_R.SetTopLeft(x, y + 135);

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
				y = y + 12;
			}
		}

		if (isDefend){
			if (dir == 1)	defendA_L.SetTopLeft(x, y + 135);
			else			defendA_R.SetTopLeft(x, y + 135);
		}



		playerA_pic1.SetTopLeft(x, y + 135);
		playerA_pic2.SetTopLeft(x, y + 135);



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

		if (counter2 + counter1 < 35){
			counter2++;
			if (isAttack && m1 > 2){           //防右攻!
				//這裡放上招式的設定
				m1 = m1 - 2;
				counter2 = 35;
			}

			if (isJump && m1 > 10){           //防右跳!
				//這裡放上招式的設定
				m1 = m1 - 10;
				counter2 = 35;
			}

		}

		if (counter3 + counter1 < 35){
			counter3++;
			if (isAttack && m1 > 2){           //防左攻!
				//這裡放上招式的設定
				m1 = m1 - 2;
				counter3 = 35;
			}

			if (isJump && m1 > 10){           //防左跳!
				//這裡放上招式的設定
				m1 = m1 - 10;
				counter3 = 35;
			}


		}

		if (counter4 + counter1 < 35){
			counter4++;
			if (isAttack && m1 > 20){           //防下攻!
				//這裡放上招式的設定
				m1 = m1 - 20;
				counter4 = 35;
			}

		}





		////////////////////////////////////////////////////////////////////////////



















	}//for -> OnMove()

	void CPlayerA::OnShow()
	{
		//////////////// 此段為測試是否有虛擬武器的運作
		if (dir == 1){
			if (isAttack){
				attackA_L.OnShow();
			}
			else if (weaponing){
				weapon.OnMove(); weapon.OnShow();
			}
		}

		else if (dir == 2){
			if (isAttack)
				attackA_R.OnShow();
			else if (weaponing){
				weapon.OnMove(); weapon.OnShow();
			}

		}



		if (dir == 1){
			if (isAttack){
				attackA_L.OnShow();
			}
			else if (isJump || isLand){
				jumpA_L.OnShow();
			}
			else if (isDefend){
				defendA_L.OnShow();
			}
			else{
				playerA_pic1.OnShow();
			}
		}
		if (dir == 2){
			if (isAttack){
				attackA_R.OnShow();
			}
			else if (isJump || isLand){
				jumpA_R.OnShow();
			}
			else if (isDefend){
				defendA_R.OnShow();
			}
			else{
				playerA_pic2.OnShow();
			}
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

	int CPlayerB::GetWeaponY(){
		return weaponY - 90;
	}

	int CPlayerB::Getb2(){
		return b2;
	}

	int CPlayerB::Getm2(){
		return m2;
	}


	bool CPlayerB::WhetherJump(){
		return isJump;
	}

	bool CPlayerB::WhetherLand(){
		return isLand;
	}


	void CPlayerB::Initialize()
	{
		const int X_POS = 360;
		const int Y_POS = 240;
		x = X_POS;
		y = Y_POS;
		b2 = 66;
		m2 = 66;
		counter1 = counter2 = counter3 = counter4 = 0;
		dir = 1;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isAttack = weaponing = isJump = isLand = isDefend = false;

	}

	void CPlayerB::LoadBitmap()
	{
		playerB_pic_left.AddBitmap(IDB_playerB, RGB(255, 255, 255));
		playerB_pic_right.AddBitmap(IDB_playerB_2, RGB(255, 255, 255));

		attackB_L.AddBitmap(IDB_AttackBL, RGB(255, 255, 255));
		attackB_R.AddBitmap(IDB_AttackBR, RGB(255, 255, 255));

		weapon.AddBitmap(IDB_Bweapon, RGB(255, 255, 255));

		jumpB_L.AddBitmap(IDB_jumpB_L, RGB(255, 255, 255));
		jumpB_R.AddBitmap(IDB_jumpB_R, RGB(255, 255, 255));

		defendB_L.AddBitmap(IDB_defendB_L, RGB(255, 255, 255));
		defendB_R.AddBitmap(IDB_defendB_R, RGB(255, 255, 255));

		runB_L.AddBitmap(IDB_runB_L, RGB(255, 255, 255));
		runB_R.AddBitmap(IDB_runB_R, RGB(255, 255, 255));
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
	void CPlayerB::OnMove()
	{
		const int STEP_SIZE = 4;

		if (isMovingLeft&&x >= -60){
			x -= STEP_SIZE;
		}
		if (isMovingRight&&x <= 700)
			x += STEP_SIZE;

		if (isMovingUp&&y >= 150)
			y -= STEP_SIZE;
		if (isMovingDown&&y <= 350)
			y += STEP_SIZE;

		if (isAttack || weaponing == true){
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
						Sleep(10);
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
						Sleep(10);
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

		} //for-> isAttack || weaponing == true

		if (isAttack && dir == 1)	attackB_L.SetTopLeft(x, y + 135);
		if (isAttack && dir == 2)	attackB_R.SetTopLeft(x, y + 135);

		if (isJump){
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
				y = y + 12;
			}
		}

		if (isDefend){
			if (dir == 1)	defendB_L.SetTopLeft(x, y + 135);
			else			defendB_R.SetTopLeft(x, y + 135);
		}

		playerB_pic_left.SetTopLeft(x, y + 135);
		playerB_pic_right.SetTopLeft(x, y + 135);

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
				counter4 = 0;   //2.防上

		}

		if (counter2 + counter1 < 35){
			counter2++;
			if (isAttack && m2 > 2){           //防右攻!
				//這裡放上招式的設定
				m2 = m2 - 2;
				counter2 = 35;
			}

			if (isJump && m2 > 10){           //防右跳!
				//這裡放上招式的設定
				m2 = m2 - 10;
				counter2 = 35;
			}

		}

		if (counter3 + counter1 < 35){
			counter3++;
			if (isAttack && m2 > 2){           //防左攻!
				//這裡放上招式的設定
				m2 = m2 - 2;
				counter3 = 35;
			}

			if (isJump && m2 > 10){           //防左跳!
				//這裡放上招式的設定
				m2 = m2 - 10;
				counter3 = 35;
			}


		}
		
		if (counter4 + counter1 < 35){
			counter4++;
			if (isJump && m2 > 20){           //防上跳!
				//這裡放上招式的設定
				m2 = m2 - 20;
				counter4 = 35;
			}

		}





////////////////////////////////////////////////////////////////////////////


	}  //for-> CPlayerB::OnMove()
	
	void CPlayerB::OnShow()
	{
		if (dir == 1){
			if (isAttack)
				attackB_L.OnShow();
			else if (weaponing){
				weapon.OnMove(); weapon.OnShow(); if (!isAttack) playerB_pic_left.OnShow();
			}
			else if (isJump || isLand){
				jumpB_L.OnShow();
				Sleep(40);
			}
			else if (isDefend){
				defendB_L.OnShow();
			}
			else
				playerB_pic_left.OnShow();
		}

		else if (dir == 2){
			if (isAttack)
				attackB_R.OnShow();
			else if (weaponing){
				weapon.OnMove(); weapon.OnShow(); if (!isAttack) playerB_pic_right.OnShow();
			}
			else if (isJump || isLand){
				jumpB_R.OnShow();
				Sleep(40);
			}
			else if (isDefend){
				defendB_R.OnShow();
			}
			else
				playerB_pic_right.OnShow();
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

		Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
		//
	}

	void CGameStateInit::OnBeginState()
	{
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_SPACE = ' ';
		if (nChar == KEY_SPACE)
			GotoGameState(GAME_STATE_RUN);						// 切換至GAME_STATE_RUN
		else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
	}

	void CGameStateInit::OnShow()
	{
		//
		// 貼上logo
		//
		logo.SetTopLeft((SIZE_X - logo.Width()) / 2, (SIZE_Y - logo.Height()) / 2);

		logo_choose.SetTopLeft((SIZE_X - logo.Width()) / 2, (SIZE_Y - logo.Height()) / 2);
		//		logo.SetTopLeft(0, 0);
		logo.ShowBitmap();
		//
		// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
		//
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
		CFont f, *fp;
		f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));
		pDC->TextOut(120, 220, "123");
		pDC->TextOut(5, 395, "456");
		if (ENABLE_GAME_PAUSE)
			pDC->TextOut(5, 425, "Press Ctrl-Q to pause the Game.");
		//	pDC->TextOut(5, 455, "Press Alt-F4 or ESC to Quit.");
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

		playerA.Initialize();
		playerA_2.Initialize();
		playerB.Initialize();
		playerB_2.Initialize();

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

		if ((playerA.GetX1() > 700 && playerB.GetX1() > 200) && (background.Left()> -800)){
			background.SetTopLeft(background.Left() - 4, 135);
			playerB.SetXY(playerB.GetX1() - 4, playerB.GetY1());
		}

		if ((playerB.GetX1() > 700 && playerA.GetX1() > 200) && (background.Left() > -800)){
			background.SetTopLeft(background.Left() - 4, 135);
			playerA.SetXY(playerA.GetX1() - 4, playerA.GetY1());
		}


		if ((playerA.GetX1() < 100 && playerB.GetX1() < 500) && (background.Left() < 0)){
			background.SetTopLeft(background.Left() + 4, 135);
			playerB.SetXY(playerB.GetX1() + 4, playerB.GetY1());
		}



		if ((playerB.GetX1() < 100 && playerA.GetX1() < 500) && (background.Left() < 0)){
			background.SetTopLeft(background.Left() + 4, 135);
			playerA.SetXY(playerA.GetX1() + 4, playerA.GetY1());
		}

		//////////////// A的普攻 扣血設定////////////////
		if (playerA.GetWeaponY() - ((playerB.GetY1() + playerB.GetY2()) / 2) > -5 &&
			playerA.GetWeaponY() - ((playerB.GetY1() + playerB.GetY2()) / 2) < 55 &&

			playerA.GetWeaponX() - ((playerB.GetX1() + playerB.GetX2()) / 2) > -10 &&
			playerA.GetWeaponX() - ((playerB.GetX1() + playerB.GetX2()) / 2) < 5)
			playerB.Setb2(-1);
	
		//////////// B的普通攻擊 扣血設定 //////////// 
		if (playerB.GetWeaponY() - ((playerA.GetY1() + playerA.GetY2()) / 2) > -10 &&      
			playerB.GetWeaponY() - ((playerA.GetY1() + playerA.GetY2()) / 2) < 60 &&

			playerB.GetWeaponX() - ((playerA.GetX1() + playerA.GetX2()) / 2) > 0 &&
			playerB.GetWeaponX() - ((playerA.GetX1() + playerA.GetX2()) / 2) < 15)
			playerA.Setb1(-1);


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

		int i;
		for (i = 0; i < NUMBALLS; i++)
			ball[i].OnMove();
		//
		// 移動擦子
		//
		eraser.OnMove();


		playerA.OnMove();
		playerB.OnMove();
		//
		// 判斷擦子是否碰到球
		//
		for (i = 0; i < NUMBALLS; i++)
			if (ball[i].IsAlive() && ball[i].HitEraser(&eraser))
			{
				ball[i].SetIsAlive(false);
				CAudio::Instance()->Play(AUDIO_DING);
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
		Last_BLeft = 0;
		I_am_counter = 0;

		int i;

		int tempTime = 0;	//test 紀錄時間
		for (i = 0; i < NUMBALLS; i++)
			ball[i].LoadBitmap();								// 載入第i個球的圖形
		eraser.LoadBitmap();
		background.LoadBitmap(IDB_mapA);					// 載入背景的圖形



		bar.LoadBitmap(IDB_bar);
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
		CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");	// 載入編號0的聲音ding.wav
		CAudio::Instance()->Load(AUDIO_LAKE, "sounds\\lake.mp3");	// 載入編號1的聲音lake.mp3
		CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");	// 載入編號2的聲音ntut.mid
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
		const char KEY_DEFEND2 = 0x34;	// keyboard 4 防禦
		

		if (nChar == KEY_LEFT){
			playerB.SetMovingLeft(true);
			playerB.SetDir(1);
			 


			int nowT = I_am_counter;
		
			

			if (nowT - Last_BLeft < 10){// 0.33秒(33m*10)內重複按的話就執行
				//playerB.SetDir(2);
			}
			Last_BLeft = nowT;

		}
		if (nChar == KEY_RIGHT){
			playerB.SetMovingRight(true);
			playerB.SetDir(2);
		}
		if (nChar == KEY_UP)
			playerB.SetMovingUp(true);
		if (nChar == KEY_DOWN)
			playerB.SetMovingDown(true);

		if (nChar == KEY_ATTACK){
			playerB.SetAttack(true);
		}
		if (nChar == KEY_JUMP && 
			!( (playerB.WhetherJump() == false && playerB.WhetherLand() == true) || 
			  (playerB.WhetherJump() == true  && playerB.WhetherLand() == false))){
			//上面兩行是避免使用者手賤讓玩家連跳造成當機
			//意思是 跳躍鍵被按下 而且 人物不得 正在往上跳或往下掉
			playerB.SetJump(true);
			playerB.SetOriginalY(playerB.GetY1());
		}

		if (nChar == KEY_DEFEND){
			playerB.SetDefend(true);
		}

		if (nChar == KEY_LEFT2){
			playerA.SetMovingLeft(true);
			playerA.SetDir(1);
		}
		if (nChar == KEY_RIGHT2){
			playerA.SetMovingRight(true);
			playerA.SetDir(2);
		}
		if (nChar == KEY_UP2)
			playerA.SetMovingUp(true);
		if (nChar == KEY_DOWN2)
			playerA.SetMovingDown(true);
		if (nChar == KEY_ATTACK2)
			playerA.SetAttack(true);
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
		const char KEY_DEFEND2 = 0x34;	// keyboard 4 防禦

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
			Sleep(200);//在放開攻擊鍵之後稍作延遲,才不會因圖片顯示太快看起來像抽搐
			playerA.SetAttack(false);/*
									 int xPos,yPos;
									 xPos = playerA.GetX1();
									 yPos = playerA.GetY1();
									 if (playerA.GetDir() == 1)	playerA.SetXY(xPos - 3 ,yPos);
									 else						playerA.SetXY(xPos + 3, yPos);*/
		}
		if (nChar == KEY_DEFEND2){
			Sleep(150);
			playerA.SetDefend(false);
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
	}
	}

		/////////////////////////////////////////