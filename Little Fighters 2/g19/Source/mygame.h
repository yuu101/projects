/////////////////////////////////////////////////////////////////////////////
// Constants
/////////////////////////////////////////////////////////////////////////////

enum AUDIO_ID  				// �w�q�U�ح��Ī��s��
{
	AUDIO_DING,				// 0
	AUDIO_LAKE,				// 1
	AUDIO_NTUT,				// 2
	AUDIO_stage1,
	AUDIO_blade,
	AUDIO_dart,
	AUDIO_DUA,
	AUDIO_energyball,
	AUDIO_energyball2,
	AUDIO_jump,
	AUDIO_missing,
	AUDIO_punch,
	AUDIO_run,
	AUDIO_victory
};

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class CEraser
	{
	public:
		CEraser();
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow();					// �N���l�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
	protected:
		CAnimation animation;		// ���l���ʵe
		int x, y;					// ���l���W���y��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
	};

	class CPlayer{
	public:
		CPlayer();
		void LoadBitmap();	//���J���a 
		void OnShow();	//��ܪ��a
		int getAX();
		int getBX();

	protected:
		CMovingBitmap player1, player2;
	};

	class CPlayerA
	{
	public:
		CPlayerA();
		int  GetX1();					// ���a���W�� x �y��
		int  GetY1();					// ���a���W�� y �y��
		int  GetX2();					// ���a�k�U�� x �y��
		int  GetY2();					// ���a�k�U�� y �y��
		int  GetDir();					// ���o���a��V
		int  GetX_forTool(int t1, int t2, int t3);			// ���o���D��ϥΪ� x �y��
		int  GetY_forTool(int t1, int t2, int t3);			// ���o���D��ϥΪ� y �y��
		bool WhetherJump();				// ���o���a�O�_���b���D
		bool WhetherLand();				// ���o���a�O�_���b����
		bool WhetherMoving();			// ���o���a�O�_���b����
		bool WhetherRuning();			// ���o���a�O�_���b�]�B
		bool WhetherDLA();		    	// ���o���a�O�_���b ���e(��)�� �����A					
		bool WhetherDRA();			    // ���o���a�O�_���b ���e(�k)�� �����A
		bool WhetherTool();				// ���o���a�O�_�����D��
		void Initialize();				// �]�w���a����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// ���ʪ��a
		void OnShow();					// �N���a�ϧζK��e��  
		void SetDir(int _dir);			// �]�w(���a�Ϥ�)��ܤ�V
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
		void SetAttack(bool flag);		// �]�w���a����
		void SetJump(bool flag);		// �]�w���a���D
		void SetOriginalY(int yPos);	// �]�w���D�e����lY��
		void SetDefend(bool flag);		// �]�w���a���m
		void SetRun(bool flag);			// �]�w���a�]�B	
		void SetWeaponNumber(int num);	// �]�w�i�s�u�ƥ�
		void SetTool(bool flag);		// �]�w�O�_�֦��D��

		int GetWeaponX();				// ����X�y��
		int GetWeaponY();  			  	// ����Y�y��
		int Getb1(); 					// ���o��q
		int Getm1();  					// ���o�]�q
		void Setb1(int n);				// �ק��q
		void Setm1(int n);  			// �ק��]�q

		int GetWeapon2Y();
		int GetWeapon3Y();
		int GetWeapon4Y();

		int GetWeapon2X();
		int GetWeapon3X();
		int GetWeapon4X();

		int GetWeaponBallX();			// ���o���e����\�y��X�y��
		int GetWeaponBallY();			// ���o���e����\�y��Y�y��

		int Getweapon_Continue1X();		// ���o���e��s�u��X�y��
		int Getweapon_Continue1Y();		// ���o���e��s�u��Y�y��
		int Getweapon_Continue2X();		// ���o���e��s�u��X�y��
		int Getweapon_Continue2Y();		// ���o���e��s�u��Y�y��
		int Getweapon_Continue3X();		// ���o���e��s�u��X�y��
		int Getweapon_Continue3Y();		// ���o���e��s�u��Y�y��
		int Getweapon_Continue4X();		// ���o���e��s�u��X�y��
		int Getweapon_Continue4Y();		// ���o���e��s�u��Y�y��
		int Getweapon_Continue5X();		// ���o���e��s�u��X�y��
		int Getweapon_Continue5Y();		// ���o���e��s�u��Y�y��

		int GetWeaponNumber();			// ���o�ثe�s�u�ƶq

		int Get_DUA_X();				// ���o���W��᪺X�y��
		int Get_DUA_Y();				// ���o���W��᪺Y�y��


	protected:
		CAnimation playerA_pic1, playerA_pic2;		// ��a����
		CAnimation playerA_walkL, playerA_walkR;	// ����
		CAnimation attackA_L, attackA_R;			// �����e����/�k
		CAnimation defendA_L, defendA_R;			// ���m�e����/�k
		CAnimation jumpA_L, jumpA_R;				// ���D�e����/�k
		CAnimation weapon;							// �����Z��
		CAnimation runA_L, runA_R;				    // �]�B�e����/�k 
		CAnimation AweaponBall_L, AweaponBall_R;	// �����ޯ�_���e��_��\�y��/�k

		CAnimation Aweapon_Continue1_L;				// �����ޯ�_���e��_�s�u_��
		CAnimation Aweapon_Continue1_R;				// �����ޯ�_���e��_�s�u_�k
		CAnimation Aweapon_Continue2_L;				// �����ޯ�_���e��_�s�u_��
		CAnimation Aweapon_Continue2_R;				// �����ޯ�_���e��_�s�u_�k
		CAnimation Aweapon_Continue3_L;				// �����ޯ�_���e��_�s�u_��
		CAnimation Aweapon_Continue3_R;				// �����ޯ�_���e��_�s�u_�k
		CAnimation Aweapon_Continue4_L;				// �����ޯ�_���e��_�s�u_��
		CAnimation Aweapon_Continue4_R;				// �����ޯ�_���e��_�s�u_�k
		CAnimation Aweapon_Continue5_L;				// �����ޯ�_���e��_�s�u_��
		CAnimation Aweapon_Continue5_R;				// �����ޯ�_���e��_�s�u_�k

		CAnimation ASkill1_L;						// �����ޯ�_���W��_�@�s��_��
		CAnimation ASkill2_L;						// �����ޯ�_���W��_�@�s��_��
		CAnimation ASkill3_L;						// �����ޯ�_���W��_�@�s��_��
		CAnimation ASkill1_R;						// �����ޯ�_���W��_�@�s��_�k
		CAnimation ASkill2_R;						// �����ޯ�_���W��_�@�s��_�k
		CAnimation ASkill3_R;						// �����ޯ�_���W��_�@�s��_�k


		int x, y;					// ���a���W���y��
		int dir, weaponDir;			//�{�b��V			
		int weaponX, weaponY;		// �Z��1�y��
		int weapon2X, weapon2Y;		// �Z��2�y��
		int weapon3X, weapon3Y;		// �Z��3�y��
		int weapon4X, weapon4Y;		// �Z��4�y��	
		int weaponBallX;			// �ޯ�_��\�yX�y��
		int weaponBallY;			// �ޯ�_��\�yY�y��

		int weapon_Continue1X;		// �ޯ�_�s�u1X�y��
		int weapon_Continue1Y;		// �ޯ�_�s�u1Y�y��
		int weapon_Continue2X;		// �ޯ�_�s�u2X�y��
		int weapon_Continue2Y;		// �ޯ�_�s�u2Y�y��
		int weapon_Continue3X;		// �ޯ�_�s�u3X�y��
		int weapon_Continue3Y;		// �ޯ�_�s�u3Y�y��
		int weapon_Continue4X;		// �ޯ�_�s�u4X�y��
		int weapon_Continue4Y;		// �ޯ�_�s�u4Y�y��
		int weapon_Continue5X;		// �ޯ�_�s�u5X�y��
		int weapon_Continue5Y;		// �ޯ�_�s�u5Y�y��

		int jumpY;					// �������D�e����lY��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isAttack;				// �O�_���b����		
		bool weaponing;				// �O�_���b�o�g�Z��		
		bool isJump;				// �O�_���b���D
		bool isLand;				// �O�_���b����(�Φb���W�����᩹�U�����L�{)
		bool isDefend;				// �O�_���b���m
		bool isRun;					// �O�_���b�]�B
		bool isDLJ;					// �O�_��Ĳ�o ���e(��)�� �ޯ�
		bool isDRJ;					// �O�_��Ĳ�o ���e(�k)�� �ޯ�
		bool isDLA;					// �O�_��Ĳ�o ���e(��)�� �ޯ�
		bool isDRA;					// �O�_��Ĳ�o ���e(��)�� �ޯ�
		bool isDUA;					// �O�_��Ĳ�o ���W�� �ޯ�
		bool DUA_bloodMinus;		// ���W�� ����O�_�w���� (�@��]true,�I��ޯ�᥼����ɤ~�Ofalse)
		bool hasTool;				// �O�_���D��

		int b1, m1;
		int counter1, counter2, counter3, counter4;				//�C33ms�]�@��Move��Show(�C��30��)
		int A_monaRecover;			// �^�]�p�ƾ�
		int A_bloodRecover;			// �^��p�ƾ�
		int weaponNumber;			// �s�u�ƶq,�S��Ĳ�o�s�u����ɬ�1
		int DUA_step;
		int A_DUAcounter;				// ����A�p��ɶ����p�ƾ�

	};

	class CPlayerB
	{
	public:
		CPlayerB();
		int  GetX1();					// ���a���W�� x �y��
		int  GetY1();					// ���a���W�� y �y��
		int  GetX2();					// ���a�k�U�� x �y��
		int  GetY2();					// ���a�k�U�� y �y��
		int  GetDir();					// ���o���a��V
		bool WhetherJump();				// ���o���a�O�_���b���D
		bool WhetherLand();				// ���o���a�O�_���b����
		bool WhetherMoving();			// ���o���a�O�_���b����
		bool WhetherRuning();			// ���o���a�O�_���b�]�B
		bool WhetherTool();				// ���o���a�O�_�����D��
		void Initialize();				// �]�w���a����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// ���ʪ��a
		void OnShow();					// �N���a�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
		void SetDir(int _dir);			// �]�w(���a�Ϥ�)��ܤ�V
		void SetAttack(bool flag);		// �]�w���a����
		void SetJump(bool flag);		// �]�w���a���D		
		void SetOriginalY(int yPos);	// �]�w���D�e����lY��
		void SetDefend(bool flag);		// �]�w���a���m
		void SetRun(bool flag);			// �]�w���a�]�B
		void SetTool(bool flag);		// �]�w�O�_�֦��D��
		void WeaponMissing();

		int GetWeaponX();				// ����X�y��
		int GetWeaponY();  			  	// ����X�y��
		int Getb2(); 					// ���o��q
		int Getm2();  					// ���o�]�q
		void Setb2(int n);				// �ק��q
		void Setm2(int n);  			// �ק��]�q

		int GetWeapon2Y();
		int GetWeapon3Y();
		int GetWeapon4Y();
		int GetWeapon5Y();

		int GetWeapon2X();
		int GetWeapon3X();
		int GetWeapon4X();
		int GetWeapon5X();
		int GetX_forTool(int t1, int t2, int t3);			// ���o���D��ϥΪ� x �y��
		int GetY_forTool(int t1, int t2, int t3);			// ���o���D��ϥΪ� y �y��


	protected:
		CAnimation playerB_pic_left, playerB_pic_right;	// ���a2���Ϥ� �R��
		CAnimation playerB_walkL, playerB_walkR;		// ���a2���Ϥ� ����
		CAnimation attackB_L, attackB_R;				// �����e����/�k
		CAnimation weapon, weapon2, weapon3;			// �Z��
		CAnimation weapon4, weapon5;				    // �Z��
		CAnimation jumpB_L, jumpB_R;					// ���D�e����/�k
		CAnimation defendB_L, defendB_R;			    // ���m�e����/�k
		CAnimation runB_L, runB_R;				        // �]�B�e����/�k 
		CAnimation B_DLJ, B_DRJ;				        // ������ ���k�� ��/�k 

		int x, y;					// ���a���W���y��
		int dir, weaponDir;		// ���a�����V , �Z���g�X��V
		int weaponX, weaponY;		// �Z��1�y��
		int weapon2X, weapon2Y;		// �Z��2�y��
		int weapon3X, weapon3Y;		// �Z��3�y��
		int weapon4X, weapon4Y;		// �Z��4�y��
		int weapon5X, weapon5Y;		// �Z��5�y��
		int jumpY;					// �������D�e����lY��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isAttack;				// �O�_���b����
		bool weaponing;				// �O�_���b�o�g�Z��
		bool isJump;				// �O�_���b��
		bool isLand;				// �O�_���b����(�Φb���W�����᩹�U�����L�{)
		bool isDefend;				// �O�_���b���m
		bool isRun;					// �O�_���b�]�B
		bool missing;
		bool hidden;				//�ۦ������N�P�_
		bool isDLA;					// �O�_Ĳ�o ���e(��)�� �ޯ�
		bool isDRA;					// �O�_Ĳ�o ���e(�k)�� �ޯ�
		bool isDLJ;					// �O�_Ĳ�o ���e(��)�� �ޯ�
		bool isDRJ;					// �O�_Ĳ�o ���e(�k)�� �ޯ�
		bool hasTool;				// �O�_���D��
		int b2, m2;
		int counter1, counter2, counter3, counter4;				//�C33ms�]�@��Move��Show(�C��30��)
		int B_monaRecover;			// �^�]�p�ƾ� 
		int B_bloodRecover;			// �^��p�ƾ� 
		int DLJ_Counter;
		int DRJ_Counter;
		int originalY;

	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class����¶��骺�y
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////



	class CBall
	{
	public:
		CBall();
		bool HitEraser(CEraser* eraser);						// �O�_�I�����l
		bool IsAlive();											// �O�_����
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx, int ny);								// �]�w��ߪ��y��
		void SetIsAlive(bool alive);							// �]�w�O�_����
		void SetDelay(int d);									// �]�w���઺�t��
	protected:
		CMovingBitmap bmp;			// �y����
		CMovingBitmap bmp_center;	// ��ߪ���
		int x, y;					// ��ߪ��y��
		int dx, dy;					// �y�Z����ߪ��첾�q
		int index;					// �y���u���סv�A0-17���0-360��
		int delay_counter;			// �վ����t�ת��p�ƾ�
		int delay;					// ���઺�t��
		bool is_alive;				// �O�_����
	private:
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// �O�_�I��Ѽƽd�򪺯x��
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѷ|�@���u�����y
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class CBouncingBall
	{
	public:
		CBouncingBall();
		void LoadBitmap();		// ���J�ϧ�
		void OnMove();			// ����
		void OnShow();			// �N�ϧζK��e��
	private:
		int x, y;				// �ϧήy��
		int floor;				// �a�O��Y�y��
		bool rising;			// true��W�ɡBfalse��U��
		int initial_velocity;	// ��l�t��
		int velocity;			// �ثe���t��(�I/��)
		CAnimation animation;	// �Q�ΰʵe�@�ϧ�
	};

	/////////////// ��Z���g������,���� ������!!!!! ///////////////

	class CWeapon{
	public:
		CWeapon();
		void Initialize();				// �]�w��l��
		void LoadBitmap();				// ���J�ϧ�
		void OnShow();					// �N�ϧζK��e��
	protected:

	private:
		CAnimation test_weapon;
	};











	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState
	{
	public:
		CGameStateInit(CGame* g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ�����
		bool isClick;									// �ƹ��O�_����"�C���}�l"������
		bool toIntroduce;								// �O�_��ܻ�����
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap logo;								// �p�B�ͻ����檺logo
		CMovingBitmap logo_choose;						// ����}�l�C������n�e�{���e��
		CMovingBitmap introduce;						// �����U���\���䪺�ϥ�


	};


	class CTool{
	public:
		CTool();
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		bool IsAlive();											// �O�_����
		void A_Take1(bool isTake);								// �]�wtool1�O�_�QA�߰_��
		void B_Take1(bool isTake);								// �]�wtool1�O�_�QB�߰_��
		void A_Take2(bool isTake);								// �]�wtool2�O�_�QA�߰_��
		void B_Take2(bool isTake);								// �]�wtool2�O�_�QB�߰_��
		void A_Take3(bool isTake);								// �]�wtool3�O�_�QA�߰_��
		void B_Take3(bool isTake);								// �]�wtool3�O�_�QB�߰_��
		bool Whether_A_Take1();									// tool1�O�_�QA�߰_��
		bool Whether_A_Take2();									// tool2�O�_�QA�߰_��
		bool Whether_A_Take3();									// tool3�O�_�QA�߰_��
		bool Whether_B_Take1();									// tool1�O�_�QB�߰_��
		bool Whether_B_Take2();									// tool2�O�_�QB�߰_��
		bool Whether_B_Take3();									// tool3�O�_�QB�߰_��
		void SetIsAlive(bool alive);							// �]�w�O�_����
		void Initialize();										// �]�w��l��
		void toolKind();										// �üƳ]�w�D��
		void GetPlayerA_X(int _AX);								// ���o���aA��X�y��
		void GetPlayerA_Y(int _AY);								// ���o���aA��Y�y��
		void GetPlayerB_X(int _BX);								// ���o���aB��X�y��		 								 
		void GetPlayerB_Y(int _BY);								// ���o���aB��Y�y��		 								 
		int GetToolAmount();									// ���o�üƨM�w���D��ƶq
		void SetShow(bool _visible, int _time);					// �]�w�O�_���
		bool GetVisible();										// ���o�O�_���
		void SetTool1XY(int x, int y);							// �]�w�y��
		int GetTool1X();
		int GetTool1Y();
		void SetTool2XY(int x, int y);							// �]�w�y��
		int GetTool2X();
		int GetTool2Y();
		void SetTool3XY(int x, int y);							// �]�w�y��
		int GetTool3X();
		int GetTool3Y();
		void SetToolAttack(bool flag, int _toolNumber);			// �]�w�ϥιD������ɪ��ƥ�		
		int GetTool1Number();									// ���o�D��1����
		int GetTool2Number();									// ���o�D��2����
		int GetTool3Number();									// ���o�D��3����
		void SetIsFirstTool(int i);								// �]�w�O�_�Ĥ@�����D����
		void _toolKind(int num);								// �@����
	protected:
		CAnimation tool1;
		CAnimation tool2;
		CAnimation tool3;
		bool is_alive; 				// �O�_����
		int toolAmount;				// �D��ƶq
		int toolNumber1;			// �D��s��				
		int toolNumber2;			// �D��s��				
		int toolNumber3;			// �D��s��		
		// 1.�j�O�� 2.���Y 3.�c�l 4.�βy 5.�u�M 6.�^�]�Ĥ� 7.�S�Y 8.�^���Ĥ�	
		int tool1X;					// �y��
		int tool1Y;
		int tool2X;
		int tool2Y;
		int tool3X;
		int tool3Y;
		int y1, y2, y3;
		int A_X;					// ���aA��X�y��
		int B_X;					// ���aB��X�y��
		int A_Y;					// ���aA��Y�y��
		int B_Y;					// ���aB��Y�y��
		int isFirstTool;			// =1�h�O�Ĥ@�����D����
		bool visible;				// �O�_��ܹD��
		bool tool1takenByA, tool1takenByB;	// �O�_�QA��B�߰_��
		bool tool2takenByA, tool2takenByB;	// �O�_�QA��B�߰_��
		bool tool3takenByA, tool3takenByB;	// �O�_�QA��B�߰_��
		bool isAttack;				// �O�_�ϥιD�����

	};


	class CTool_HAHA{
	public:
		CTool_HAHA();
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		void Initialize();										// �]�w��l��
		void toolKind();										// �üƳ]�w�D��
		void GetPlayerA_X(int _AX);								// ���o���aA��X�y��
		void GetPlayerA_Y(int _AY);								// ���o���aA��Y�y��
		void GetPlayerB_X(int _BX);								// ���o���aB��X�y��		 								 
		void GetPlayerB_Y(int _BY);								// ���o���aB��Y�y��		 								 
		int GetToolAmount();									// ���o�üƨM�w���D��ƶq
		void SetShow(bool _visible, int _time);					// �]�w�O�_���
		bool GetVisible();										// ���o�O�_���
		void SetTool1XY(int x, int y);							// �]�w�y��
		int GetTool1X();
		int GetTool1Y();
		void SetTool2XY(int x, int y);							// �]�w�y��
		int GetTool2X();
		int GetTool2Y();
		void SetTool3XY(int x, int y);							// �]�w�y��
		int GetTool3X();
		int GetTool3Y();
		int GetTool1Number();									// ���o�D��1����
		int GetTool2Number();									// ���o�D��2����
		int GetTool3Number();									// ���o�D��3����
		void SetIsFirstTool(int i);								// �]�w�O�_�Ĥ@�����D����
	protected:
		CAnimation tool1;
		CAnimation tool2;
		CAnimation tool3;
		int toolAmount;				// �D��ƶq
		int toolNumber1;			// �D��s��				
		int toolNumber2;			// �D��s��				
		int toolNumber3;			// �D��s��		
		// 1.�j�O�� 2.���Y 3.�c�l 4.�βy 5.�u�M 6.�^�]�Ĥ� 7.�S�Y 8.�^���Ĥ�	
		int tool1X;					// �y��
		int tool1Y;
		int tool2X;
		int tool2Y;
		int tool3X;
		int tool3Y;
		int y1, y2, y3;
		int A_X;					// ���aA��X�y��
		int B_X;					// ���aB��X�y��
		int A_Y;					// ���aA��Y�y��
		int B_Y;					// ���aB��Y�y��
		int isFirstTool;			// =1�h�O�Ĥ@�����D����
		bool visible;				// �O�_��ܹD��
		bool tool1takenByA, tool1takenByB;	// �O�_�QA��B�߰_��
		bool tool2takenByA, tool2takenByB;	// �O�_�QA��B�߰_��
		bool tool3takenByA, tool3takenByB;	// �O�_�QA��B�߰_��

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
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState
	{
	public:
		CGameStateRun(CGame* g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		//void makeDumpTool();							// �ͦ��ŭ��D��
		//void DumpTool();								// �ŭ��D�㭰���B�z
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:

		const int		NUMBALLS;	// �y���`��
		CMovingBitmap	background;	// �I����
		CMovingBitmap	bar;		// ���A��
		CMovingBitmap	help;		// ������
		CBall*			ball;		// �y���}�C
		CMovingBitmap	corner;		// ������
		CEraser			eraser;		// ��l
		CPlayerA        playerA, playerA_2;//����A,1����ܥk��A2����ܥ���
		CPlayerB        playerB, playerB_2;//����B,1����ܥk��A2����ܥ���
		CInteger		hits_left;	// �ѤU��������
		CBouncingBall   bball;		// ���мu�����y
		CTool tool1A;
		CTool_HAHA tool1B, tool1C, tool2A, tool2B, tool2C;
		CTool_HAHA tool3A, tool3B, tool3C;

		CMovingBitmap	player1, player2;	// �H���� 
		CMovingBitmap playerA_logo, playerB_logo;		// A,B���a���Y��

		CAnimation	endA;		// A����
		CAnimation	endB;		// B����

		int I_am_counter;			// ��ɶ�

		int Last_ALeft;				// �������aA�W�@�������䪺�ɶ�
		int Last_ARight;			// �������aA�W�@�����k�䪺�ɶ�
		int A_lastClick;			// �W�@�����aA������,�]�w1��,2�k,3�W,4�U,5����,6��,7���m  

		int Last_BLeft;				// �������aB�W�@�������䪺�ɶ�
		int Last_BRight;			// �������aB�W�@�����k�䪺�ɶ�
		int B_lastClick;			// �W�@�����aB������,�]�w1��,2�k,3�W,4�U,5����,6��,7���m
		int firstTool;				// �����O���O�Ĥ@�����D����(�@����)


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
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState
	{
	public:
		CGameStateOver(CGame* g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int counter;	// �˼Ƥ��p�ƾ�

	};



}

