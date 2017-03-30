/////////////////////////////////////////////////////////////////////////////
// Constants
/////////////////////////////////////////////////////////////////////////////

enum AUDIO_ID  				// 定義各種音效的編號
{
	AUDIO_DING,				// 0
	AUDIO_LAKE,				// 1
	AUDIO_NTUT				// 2
};

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////

	class CEraser
	{
	public:
		CEraser();
		int  GetX1();					// 擦子左上角 x 座標
		int  GetY1();					// 擦子左上角 y 座標
		int  GetX2();					// 擦子右下角 x 座標
		int  GetY2();					// 擦子右下角 y 座標
		void Initialize();				// 設定擦子為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow();					// 將擦子圖形貼到畫面
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetXY(int nx, int ny);		// 設定擦子左上角座標
	protected:
		CAnimation animation;		// 擦子的動畫
		int x, y;					// 擦子左上角座標
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
	};

	class CPlayer{
	public:
		CPlayer();
		void LoadBitmap();	//載入玩家 
		void OnShow();	//顯示玩家
		int getAX();
		int getBX();

	protected:
		CMovingBitmap player1, player2;
	};

	class CPlayerA
	{
	public:
		CPlayerA();
		int  GetX1();					// 玩家左上角 x 座標
		int  GetY1();					// 玩家左上角 y 座標
		int  GetX2();					// 玩家右下角 x 座標
		int  GetY2();					// 玩家右下角 y 座標
		int  GetDir();					// 取得玩家方向
		bool WhetherJump();				// 取得玩家是否正在跳躍
		bool WhetherLand();				// 取得玩家是否正在降落
		void Initialize();				// 設定玩家為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動玩家
		void OnShow();					// 將玩家圖形貼到畫面  
		void SetDir(int _dir);			// 設定(玩家圖片)顯示方向
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetXY(int nx, int ny);		// 設定擦子左上角座標
		void SetAttack(bool flag);		// 設定玩家攻擊
		void SetJump(bool flag);		// 設定玩家跳躍
		void SetOriginalY(int yPos);	// 設定跳躍前的初始Y值
		void SetDefend(bool flag);		// 設定玩家防禦

		int GetWeaponX();				// 普攻的X座標
		int GetWeaponY();  			  	// 普攻的X座標
		int Getb1(); 					// 取得血量
		int Getm1();  					// 取得魔量
		void Setb1(int n);				// 修改血量
		void Setm1(int n);  			// 修改魔量
		
	protected:
		CAnimation playerA_pic1, playerA_pic2;		// 動畫
		CAnimation attackA_L, attackA_R;			// 攻擊畫面左/右
		CAnimation defendA_L, defendA_R;			// 防禦畫面左/右
		CAnimation jumpA_L, jumpA_R;				// 跳躍畫面左/右
		CAnimation weapon;							// 虛擬武器
		CAnimation runA_L, runA_R;				    // 跑步畫面左/右

		int x, y;					// 玩家左上角座標
		int dir, weaponDir;			//現在方向			
		int weaponX, weaponY;		// 武器1座標	
		int jumpY;					// 紀錄跳躍前的初始Y值
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool isAttack;				//是否正在攻擊		
		bool weaponing;				// 是否正在發射武器		
		bool isJump;				// 是否正在跳躍
		bool isLand;				// 是否正在降落(用在往上跳之後往下跳的過程)
		bool isDefend;				// 是否正在防禦
		int b1,m1;					
		int counter1, counter2, counter3, counter4;				//每33ms跑一次Move及Show(每秒30次)
	};

	class CPlayerB
	{
	public:
		CPlayerB();
		int  GetX1();					// 玩家左上角 x 座標
		int  GetY1();					// 玩家左上角 y 座標
		int  GetX2();					// 玩家右下角 x 座標
		int  GetY2();					// 玩家右下角 y 座標
		int  GetDir();					// 取得玩家方向
		bool WhetherJump();				// 取得玩家是否正在跳躍
		bool WhetherLand();				// 取得玩家是否正在降落
		void Initialize();				// 設定玩家為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動玩家
		void OnShow();					// 將玩家圖形貼到畫面
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetXY(int nx, int ny);		// 設定擦子左上角座標
		void SetDir(int _dir);			// 設定(玩家圖片)顯示方向
		void SetAttack(bool flag);		// 設定玩家攻擊
		void SetJump(bool flag);		// 設定玩家跳躍		
		void SetOriginalY(int yPos);	// 設定跳躍前的初始Y值
		void SetDefend(bool flag);		// 設定玩家防禦

		int GetWeaponX();				// 普攻的X座標
		int GetWeaponY();  			  	// 普攻的X座標
		int Getb2(); 					// 取得血量
		int Getm2();  					// 取得魔量
		void Setb2(int n);				// 修改血量
		void Setm2(int n);  			// 修改魔量

	protected:
		CAnimation playerB_pic_left, playerB_pic_right;	// 玩家2的圖片左/右
		CAnimation attackB_L, attackB_R;				// 攻擊畫面左/右
		CAnimation weapon,weapon2,weapon3;				// 武器,二連發,三連發
		CAnimation jumpB_L, jumpB_R;					// 跳躍畫面左/右
		CAnimation defendB_L, defendB_R;			    // 防禦畫面左/右
		CAnimation runB_L, runB_R;				        // 跑步畫面左/右


		int x, y;					// 玩家左上角座標
		int dir , weaponDir;		// 玩家面對方向 , 武器射出方向
		int weaponX, weaponY;		// 武器1座標
		int weaponX2, weaponY2;		// 武器2座標
		int weaponX3, weaponY3;		// 武器3座標
		int jumpY;					// 紀錄跳躍前的初始Y值
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool isAttack;				// 是否正在攻擊
		bool weaponing;				// 是否正在發射武器
		bool isJump;				// 是否正在跳
		bool isLand;				// 是否正在降落(用在往上跳之後往下跳的過程)
		bool isDefend;				// 是否正在防禦
		int b2,m2;
		int counter1,counter2,counter3,counter4;				//每33ms跑一次Move及Show(每秒30次)
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供繞圈圈的球
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////



	class CBall
	{
	public:
		CBall();
		bool HitEraser(CEraser* eraser);						// 是否碰到擦子
		bool IsAlive();											// 是否活著
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetXY(int nx, int ny);								// 設定圓心的座標
		void SetIsAlive(bool alive);							// 設定是否活著
		void SetDelay(int d);									// 設定旋轉的速度
	protected:
		CMovingBitmap bmp;			// 球的圖
		CMovingBitmap bmp_center;	// 圓心的圖
		int x, y;					// 圓心的座標
		int dx, dy;					// 球距離圓心的位移量
		int index;					// 球的「角度」，0-17表示0-360度
		int delay_counter;			// 調整旋轉速度的計數器
		int delay;					// 旋轉的速度
		bool is_alive;				// 是否活著
	private:
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// 是否碰到參數範圍的矩形
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供會一直彈跳的球
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////

	class CBouncingBall
	{
	public:
		CBouncingBall();
		void LoadBitmap();		// 載入圖形
		void OnMove();			// 移動
		void OnShow();			// 將圖形貼到畫面
	private:
		int x, y;				// 圖形座標
		int floor;				// 地板的Y座標
		bool rising;			// true表上升、false表下降
		int initial_velocity;	// 初始速度
		int velocity;			// 目前的速度(點/次)
		CAnimation animation;	// 利用動畫作圖形
	};

	/////////////// 把武器寫成物件,測試中!!!!! ///////////////

	class CWeapon{
	public:
		CWeapon();	
		void Initialize();				// 設定初始值
		void LoadBitmap();				// 載入圖形
		void OnShow();					// 將圖形貼到畫面
	protected:
		 								 
	private:
		CAnimation test_weapon;
	};











	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState
	{
	public:
		CGameStateInit(CGame* g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap logo;								// 小朋友齊打交的logo
		CMovingBitmap logo_choose;						// 選取開始遊戲之後要呈現的畫面
		
	};



	class CMap{
	public:
		CMap();
		void LoadBitmap();
		void OnMove();
		void OnShow();
	private:
		CMovingBitmap backwall;
		int x, y;
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState
	{
	public:
		CGameStateRun(CGame* g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
 
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:

		const int		NUMBALLS;	// 球的總數
		CMovingBitmap	background;	// 背景圖
		CMovingBitmap	bar;		// 狀態圖
		CMovingBitmap	help;		// 說明圖
		CBall*			ball;		// 球的陣列
		CMovingBitmap	corner;		// 角落圖
		CEraser			eraser;		// 拍子
		CPlayerA        playerA, playerA_2;//角色A,1為顯示右邊，2為顯示左邊
		CPlayerB        playerB, playerB_2;//角色B,1為顯示右邊，2為顯示左邊
		CInteger		hits_left;	// 剩下的撞擊數
		CBouncingBall   bball;		// 反覆彈跳的球

		CMovingBitmap	player1, player2;	// 人物圖 

		int Last_BLeft;				// test 紀錄時間(cycle)
		int I_am_counter;			// test 抓時間= =

	/////////////////////////////////////////////////
	CMovingBitmap	blood1;
	CMovingBitmap	blood10;
	CMovingBitmap	blood11;
	CMovingBitmap	blood12;
	CMovingBitmap	blood13;
	CMovingBitmap	blood14;
	CMovingBitmap	blood15;
	CMovingBitmap	blood16;
	CMovingBitmap	blood17;
	CMovingBitmap	blood18;
	CMovingBitmap	blood19;

	CMovingBitmap	blood2;
	CMovingBitmap	blood20;
	CMovingBitmap	blood21;
	CMovingBitmap	blood22;
	CMovingBitmap	blood23;
	CMovingBitmap	blood24;
	CMovingBitmap	blood25;
	CMovingBitmap	blood26;
	CMovingBitmap	blood27;
	CMovingBitmap	blood28;
	CMovingBitmap	blood29;

	CMovingBitmap	blood3;
	CMovingBitmap	blood30;
	CMovingBitmap	blood31;
	CMovingBitmap	blood32;
	CMovingBitmap	blood33;
	CMovingBitmap	blood34;
	CMovingBitmap	blood35;
	CMovingBitmap	blood36;
	CMovingBitmap	blood37;
	CMovingBitmap	blood38;
	CMovingBitmap	blood39;

	CMovingBitmap	blood4;
	CMovingBitmap	blood40;
	CMovingBitmap	blood41;
	CMovingBitmap	blood42;
	CMovingBitmap	blood43;
	CMovingBitmap	blood44;
	CMovingBitmap	blood45;
	CMovingBitmap	blood46;
	CMovingBitmap	blood47;
	CMovingBitmap	blood48;
	CMovingBitmap	blood49;

	CMovingBitmap	blood5;
	CMovingBitmap	blood50;
	CMovingBitmap	blood51;
	CMovingBitmap	blood52;
	CMovingBitmap	blood53;
	CMovingBitmap	blood54;
	CMovingBitmap	blood55;
	CMovingBitmap	blood56;
	CMovingBitmap	blood57;
	CMovingBitmap	blood58;
	CMovingBitmap	blood59;

	CMovingBitmap	blood6;
	CMovingBitmap	blood60;
	CMovingBitmap	blood61;
	CMovingBitmap	blood62;
	CMovingBitmap	blood63;
	CMovingBitmap	blood64;
	CMovingBitmap	blood65;
	CMovingBitmap	blood66;
	CMovingBitmap	blood67;
	CMovingBitmap	blood68;
	CMovingBitmap	blood69;

	CMovingBitmap	blood7;
	///////////////////////////////////////////////////

	CMovingBitmap	blood_2_1;
	CMovingBitmap	blood_2_10;
	CMovingBitmap	blood_2_11;
	CMovingBitmap	blood_2_12;
	CMovingBitmap	blood_2_13;
	CMovingBitmap	blood_2_14;
	CMovingBitmap	blood_2_15;
	CMovingBitmap	blood_2_16;
	CMovingBitmap	blood_2_17;
	CMovingBitmap	blood_2_18;
	CMovingBitmap	blood_2_19;

	CMovingBitmap	blood_2_2;
	CMovingBitmap	blood_2_20;
	CMovingBitmap	blood_2_21;
	CMovingBitmap	blood_2_22;
	CMovingBitmap	blood_2_23;
	CMovingBitmap	blood_2_24;
	CMovingBitmap	blood_2_25;
	CMovingBitmap	blood_2_26;
	CMovingBitmap	blood_2_27;
	CMovingBitmap	blood_2_28;
	CMovingBitmap	blood_2_29;

	CMovingBitmap	blood_2_3;
	CMovingBitmap	blood_2_30;
	CMovingBitmap	blood_2_31;
	CMovingBitmap	blood_2_32;
	CMovingBitmap	blood_2_33;
	CMovingBitmap	blood_2_34;
	CMovingBitmap	blood_2_35;
	CMovingBitmap	blood_2_36;
	CMovingBitmap	blood_2_37;
	CMovingBitmap	blood_2_38;
	CMovingBitmap	blood_2_39;

	CMovingBitmap	blood_2_4;
	CMovingBitmap	blood_2_40;
	CMovingBitmap	blood_2_41;
	CMovingBitmap	blood_2_42;
	CMovingBitmap	blood_2_43;
	CMovingBitmap	blood_2_44;
	CMovingBitmap	blood_2_45;
	CMovingBitmap	blood_2_46;
	CMovingBitmap	blood_2_47;
	CMovingBitmap	blood_2_48;
	CMovingBitmap	blood_2_49;

	CMovingBitmap	blood_2_5;
	CMovingBitmap	blood_2_50;
	CMovingBitmap	blood_2_51;
	CMovingBitmap	blood_2_52;
	CMovingBitmap	blood_2_53;
	CMovingBitmap	blood_2_54;
	CMovingBitmap	blood_2_55;
	CMovingBitmap	blood_2_56;
	CMovingBitmap	blood_2_57;
	CMovingBitmap	blood_2_58;
	CMovingBitmap	blood_2_59;

	CMovingBitmap	blood_2_6;
	CMovingBitmap	blood_2_60;
	CMovingBitmap	blood_2_61;
	CMovingBitmap	blood_2_62;
	CMovingBitmap	blood_2_63;
	CMovingBitmap	blood_2_64;
	CMovingBitmap	blood_2_65;
	CMovingBitmap	blood_2_66;
	CMovingBitmap	blood_2_67;
	CMovingBitmap	blood_2_68;
	CMovingBitmap	blood_2_69;

	CMovingBitmap	blood_2_7;

	////////////////////////////////////////////////////////
	CMovingBitmap	mana1;
	CMovingBitmap	mana10;
	CMovingBitmap	mana11;
	CMovingBitmap	mana12;
	CMovingBitmap	mana13;
	CMovingBitmap	mana14;
	CMovingBitmap	mana15;
	CMovingBitmap	mana16;
	CMovingBitmap	mana17;
	CMovingBitmap	mana18;
	CMovingBitmap	mana19;

	CMovingBitmap	mana2;
	CMovingBitmap	mana20;
	CMovingBitmap	mana21;
	CMovingBitmap	mana22;
	CMovingBitmap	mana23;
	CMovingBitmap	mana24;
	CMovingBitmap	mana25;
	CMovingBitmap	mana26;
	CMovingBitmap	mana27;
	CMovingBitmap	mana28;
	CMovingBitmap	mana29;

	CMovingBitmap	mana3;
	CMovingBitmap	mana30;
	CMovingBitmap	mana31;
	CMovingBitmap	mana32;
	CMovingBitmap	mana33;
	CMovingBitmap	mana34;
	CMovingBitmap	mana35;
	CMovingBitmap	mana36;
	CMovingBitmap	mana37;
	CMovingBitmap	mana38;
	CMovingBitmap	mana39;

	CMovingBitmap	mana4;
	CMovingBitmap	mana40;
	CMovingBitmap	mana41;
	CMovingBitmap	mana42;
	CMovingBitmap	mana43;
	CMovingBitmap	mana44;
	CMovingBitmap	mana45;
	CMovingBitmap	mana46;
	CMovingBitmap	mana47;
	CMovingBitmap	mana48;
	CMovingBitmap	mana49;

	CMovingBitmap	mana5;
	CMovingBitmap	mana50;
	CMovingBitmap	mana51;
	CMovingBitmap	mana52;
	CMovingBitmap	mana53;
	CMovingBitmap	mana54;
	CMovingBitmap	mana55;
	CMovingBitmap	mana56;
	CMovingBitmap	mana57;
	CMovingBitmap	mana58;
	CMovingBitmap	mana59;

	CMovingBitmap	mana6;
	CMovingBitmap	mana60;
	CMovingBitmap	mana61;
	CMovingBitmap	mana62;
	CMovingBitmap	mana63;
	CMovingBitmap	mana64;
	CMovingBitmap	mana65;
	CMovingBitmap	mana66;
	CMovingBitmap	mana67;
	CMovingBitmap	mana68;
	CMovingBitmap	mana69;

	CMovingBitmap	mana7;

	////////////////////////////////////////////////
	CMovingBitmap	mana_2_1;
	CMovingBitmap	mana_2_10;
	CMovingBitmap	mana_2_11;
	CMovingBitmap	mana_2_12;
	CMovingBitmap	mana_2_13;
	CMovingBitmap	mana_2_14;
	CMovingBitmap	mana_2_15;
	CMovingBitmap	mana_2_16;
	CMovingBitmap	mana_2_17;
	CMovingBitmap	mana_2_18;
	CMovingBitmap	mana_2_19;

	CMovingBitmap	mana_2_2;
	CMovingBitmap	mana_2_20;
	CMovingBitmap	mana_2_21;
	CMovingBitmap	mana_2_22;
	CMovingBitmap	mana_2_23;
	CMovingBitmap	mana_2_24;
	CMovingBitmap	mana_2_25;
	CMovingBitmap	mana_2_26;
	CMovingBitmap	mana_2_27;
	CMovingBitmap	mana_2_28;
	CMovingBitmap	mana_2_29;

	CMovingBitmap	mana_2_3;
	CMovingBitmap	mana_2_30;
	CMovingBitmap	mana_2_31;
	CMovingBitmap	mana_2_32;
	CMovingBitmap	mana_2_33;
	CMovingBitmap	mana_2_34;
	CMovingBitmap	mana_2_35;
	CMovingBitmap	mana_2_36;
	CMovingBitmap	mana_2_37;
	CMovingBitmap	mana_2_38;
	CMovingBitmap	mana_2_39;

	CMovingBitmap	mana_2_4;
	CMovingBitmap	mana_2_40;
	CMovingBitmap	mana_2_41;
	CMovingBitmap	mana_2_42;
	CMovingBitmap	mana_2_43;
	CMovingBitmap	mana_2_44;
	CMovingBitmap	mana_2_45;
	CMovingBitmap	mana_2_46;
	CMovingBitmap	mana_2_47;
	CMovingBitmap	mana_2_48;
	CMovingBitmap	mana_2_49;

	CMovingBitmap	mana_2_5;
	CMovingBitmap	mana_2_50;
	CMovingBitmap	mana_2_51;
	CMovingBitmap	mana_2_52;
	CMovingBitmap	mana_2_53;
	CMovingBitmap	mana_2_54;
	CMovingBitmap	mana_2_55;
	CMovingBitmap	mana_2_56;
	CMovingBitmap	mana_2_57;
	CMovingBitmap	mana_2_58;
	CMovingBitmap	mana_2_59;

	CMovingBitmap	mana_2_6;
	CMovingBitmap	mana_2_60;
	CMovingBitmap	mana_2_61;
	CMovingBitmap	mana_2_62;
	CMovingBitmap	mana_2_63;
	CMovingBitmap	mana_2_64;
	CMovingBitmap	mana_2_65;
	CMovingBitmap	mana_2_66;
	CMovingBitmap	mana_2_67;
	CMovingBitmap	mana_2_68;
	CMovingBitmap	mana_2_69;

	CMovingBitmap	mana_2_7;

	/////////////////////////////////////////////////

	};


	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState
	{
	public:
		CGameStateOver(CGame* g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;	// 倒數之計數器
		 
	};




	//test 取得cycle數 失敗中
	class TellMeTime :public CSpecialEffect{
	public:
		int GetCurrentTimeCount();				// 讀取儲存ctime的次數
	private:
		int count;
		int ctime;
		
	};

}

