#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define srep(i, s, n) for (int i = int(s); i < int(s + n); ++i)

char WindowTitle[] = "ルービックキューブ";
int flag = -1;
int f = -1;
int r[] = {0, 0}; /* 回転角 */
int tmp = 0;
bool rlist[][27] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}};
int facelist[27] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
bool faceflg[27] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int colorlist[27][6] = {{0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}, {0, 1, 2, 3, 4, 5}};
const double size = 1.0;
int stat = -1;
GLfloat light0pos[] = {5.0, 5.0, 5.0, 1.0};

// マウスのドラッグのための変数
int drag_mouse_r = 0; // 右ボタンをドラッグ中かどうかのフラグ（0:非ドラッグ中,1:ドラッグ中）
int drag_mouse_l = 0; // 左ボタンをドラッグ中かどうかのフラグ（0:非ドラッグ中,1:ドラッグ中）
int last_mouse_x;     // 最後に記録されたマウスカーソルのＸ座標
int last_mouse_y;     // 最後に記録されたマウスカーソルのＹ座標

void facemove(int s, int flag)
{ //横回転
    int tmplist[27];
    int colortmp[27][6];
    rep(i, 3)
    {
        rep(j, 3)
        {
            rep(k, 3)
            {
                printf("%2d ", facelist[18 + k + 3 * j - 9 * i]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
    if (s == 0)
    {
        if (flag == 3)
            f = 0;
        if (flag == 2)
            f = 1;
        if (flag == 1)
            f = 2;

        rep(i, 9)
        {
            tmplist[18 + i - 9 * f] = facelist[18 + i - 9 * f];
            printf("facelist[18 + i - 9 * f]=facelist[18 + %2d - 9 * %2d]%2d\n", i, f, facelist[18 + i - 9 * f]);
            rep(j, 6)
            {
                colortmp[18 + i - 9 * f][j] = colorlist[18 + i - 9 * f][j];
            }
        }
        facelist[18 - 9 * f] = tmplist[20 - 9 * f];
        facelist[20 - 9 * f] = tmplist[26 - 9 * f];
        facelist[26 - 9 * f] = tmplist[24 - 9 * f];
        facelist[24 - 9 * f] = tmplist[18 - 9 * f];
        facelist[19 - 9 * f] = tmplist[23 - 9 * f];
        facelist[23 - 9 * f] = tmplist[25 - 9 * f];
        facelist[25 - 9 * f] = tmplist[21 - 9 * f];
        facelist[21 - 9 * f] = tmplist[19 - 9 * f];
        colorlist[26 - 9 * f][0] = colortmp[20 - 9 * f][3];
        colorlist[26 - 9 * f][1] = colortmp[20 - 9 * f][0];
        colorlist[26 - 9 * f][2] = colortmp[20 - 9 * f][2];
        colorlist[26 - 9 * f][3] = colortmp[20 - 9 * f][5];
        colorlist[26 - 9 * f][4] = colortmp[20 - 9 * f][4];
        colorlist[26 - 9 * f][5] = colortmp[20 - 9 * f][1];
        colorlist[20 - 9 * f][0] = colortmp[18 - 9 * f][3];
        colorlist[20 - 9 * f][1] = colortmp[18 - 9 * f][0];
        colorlist[20 - 9 * f][2] = colortmp[18 - 9 * f][2];
        colorlist[20 - 9 * f][3] = colortmp[18 - 9 * f][5];
        colorlist[20 - 9 * f][4] = colortmp[18 - 9 * f][4];
        colorlist[20 - 9 * f][5] = colortmp[18 - 9 * f][1];
        colorlist[18 - 9 * f][0] = colortmp[24 - 9 * f][3];
        colorlist[18 - 9 * f][1] = colortmp[24 - 9 * f][0];
        colorlist[18 - 9 * f][2] = colortmp[24 - 9 * f][2];
        colorlist[18 - 9 * f][3] = colortmp[24 - 9 * f][5];
        colorlist[18 - 9 * f][4] = colortmp[24 - 9 * f][4];
        colorlist[18 - 9 * f][5] = colortmp[24 - 9 * f][1];
        colorlist[24 - 9 * f][0] = colortmp[26 - 9 * f][3];
        colorlist[24 - 9 * f][1] = colortmp[26 - 9 * f][0];
        colorlist[24 - 9 * f][2] = colortmp[26 - 9 * f][2];
        colorlist[24 - 9 * f][3] = colortmp[26 - 9 * f][5];
        colorlist[24 - 9 * f][4] = colortmp[26 - 9 * f][4];
        colorlist[24 - 9 * f][5] = colortmp[26 - 9 * f][1];

        colorlist[23 - 9 * f][0] = colortmp[19 - 9 * f][3]; //19
        colorlist[23 - 9 * f][1] = colortmp[19 - 9 * f][0];
        colorlist[23 - 9 * f][2] = colortmp[19 - 9 * f][2];
        colorlist[23 - 9 * f][3] = colortmp[19 - 9 * f][5];
        colorlist[23 - 9 * f][4] = colortmp[19 - 9 * f][4];
        colorlist[23 - 9 * f][5] = colortmp[19 - 9 * f][1];
        colorlist[25 - 9 * f][0] = colortmp[23 - 9 * f][3]; //23
        colorlist[25 - 9 * f][1] = colortmp[23 - 9 * f][0];
        colorlist[25 - 9 * f][2] = colortmp[23 - 9 * f][2];
        colorlist[25 - 9 * f][3] = colortmp[23 - 9 * f][5];
        colorlist[25 - 9 * f][4] = colortmp[23 - 9 * f][4];
        colorlist[25 - 9 * f][5] = colortmp[23 - 9 * f][1];
        colorlist[21 - 9 * f][0] = colortmp[25 - 9 * f][3]; //25
        colorlist[21 - 9 * f][1] = colortmp[25 - 9 * f][0];
        colorlist[21 - 9 * f][2] = colortmp[25 - 9 * f][2];
        colorlist[21 - 9 * f][3] = colortmp[25 - 9 * f][5];
        colorlist[21 - 9 * f][4] = colortmp[25 - 9 * f][4];
        colorlist[21 - 9 * f][5] = colortmp[25 - 9 * f][1];
        colorlist[19 - 9 * f][0] = colortmp[21 - 9 * f][3]; //21
        colorlist[19 - 9 * f][1] = colortmp[21 - 9 * f][0];
        colorlist[19 - 9 * f][2] = colortmp[21 - 9 * f][2];
        colorlist[19 - 9 * f][3] = colortmp[21 - 9 * f][5];
        colorlist[19 - 9 * f][4] = colortmp[21 - 9 * f][4];
        colorlist[19 - 9 * f][5] = colortmp[21 - 9 * f][1];
    }
    if (s == 1) //縦回転
    {
        if (flag == 3)
            f = 0;
        if (flag == 2)
            f = 1;
        if (flag == 1)
            f = 2;

        rep(i, 27)
        {
            tmplist[i] = facelist[i];
            rep(j, 6)
            {
                colortmp[i][j] = colorlist[i][j];
            }
        }
        facelist[2 - f] = tmplist[8 - f];
        facelist[8 - f] = tmplist[26 - f];
        facelist[26 - f] = tmplist[20 - f];
        facelist[20 - f] = tmplist[2 - f];
        facelist[11 - f] = tmplist[5 - f];
        facelist[5 - f] = tmplist[17 - f];
        facelist[17 - f] = tmplist[23 - f];
        facelist[23 - f] = tmplist[11 - f];

        colorlist[8 - f][0] = colortmp[2 - f][2]; //8
        colorlist[8 - f][1] = colortmp[2 - f][1];
        colorlist[8 - f][2] = colortmp[2 - f][5];
        colorlist[8 - f][3] = colortmp[2 - f][3];
        colorlist[8 - f][4] = colortmp[2 - f][0];
        colorlist[8 - f][5] = colortmp[2 - f][4];
        colorlist[26 - f][0] = colortmp[8 - f][2]; //8
        colorlist[26 - f][1] = colortmp[8 - f][1];
        colorlist[26 - f][2] = colortmp[8 - f][5];
        colorlist[26 - f][3] = colortmp[8 - f][3];
        colorlist[26 - f][4] = colortmp[8 - f][0];
        colorlist[26 - f][5] = colortmp[8 - f][4];
        colorlist[20 - f][0] = colortmp[26 - f][2]; //20
        colorlist[20 - f][1] = colortmp[26 - f][1];
        colorlist[20 - f][2] = colortmp[26 - f][5];
        colorlist[20 - f][3] = colortmp[26 - f][3];
        colorlist[20 - f][4] = colortmp[26 - f][0];
        colorlist[20 - f][5] = colortmp[26 - f][4];
        colorlist[2 - f][0] = colortmp[20 - f][2]; //2
        colorlist[2 - f][1] = colortmp[20 - f][1];
        colorlist[2 - f][2] = colortmp[20 - f][5];
        colorlist[2 - f][3] = colortmp[20 - f][3];
        colorlist[2 - f][4] = colortmp[20 - f][0];
        colorlist[2 - f][5] = colortmp[20 - f][4];

        colorlist[5 - f][0] = colortmp[11 - f][2];
        colorlist[5 - f][1] = colortmp[11 - f][1];
        colorlist[5 - f][2] = colortmp[11 - f][5];
        colorlist[5 - f][3] = colortmp[11 - f][3];
        colorlist[5 - f][4] = colortmp[11 - f][0];
        colorlist[5 - f][5] = colortmp[11 - f][4];
        colorlist[17 - f][0] = colortmp[5 - f][2];
        colorlist[17 - f][1] = colortmp[5 - f][1];
        colorlist[17 - f][2] = colortmp[5 - f][5];
        colorlist[17 - f][3] = colortmp[5 - f][3];
        colorlist[17 - f][4] = colortmp[5 - f][0];
        colorlist[17 - f][5] = colortmp[5 - f][4];
        colorlist[23 - f][0] = colortmp[17 - f][2];
        colorlist[23 - f][1] = colortmp[17 - f][1];
        colorlist[23 - f][2] = colortmp[17 - f][5];
        colorlist[23 - f][3] = colortmp[17 - f][3];
        colorlist[23 - f][4] = colortmp[17 - f][0];
        colorlist[23 - f][5] = colortmp[17 - f][4];
        colorlist[11 - f][0] = colortmp[23 - f][2];
        colorlist[11 - f][1] = colortmp[23 - f][1];
        colorlist[11 - f][2] = colortmp[23 - f][5];
        colorlist[11 - f][3] = colortmp[23 - f][3];
        colorlist[11 - f][4] = colortmp[23 - f][0];
        colorlist[11 - f][5] = colortmp[23 - f][4];
    }
    /*rep(i, 9)
	{
		rep(j, 6)
		{
			printf("colorlist[%2d][%2d]=%2d\n", 18 + i, j, colorlist[18 + i][j]);
		}
	}*/
    rep(i, 3)
    {
        rep(j, 3)
        {
            rep(k, 3)
            {
                printf("%2d ", facelist[18 + k + 3 * j - 9 * i]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void cube(int n)
{
    const double size = 1.0;
    double px = (double)(n % 3) - 1.0;
    double py = (double)((n / 3) % 3) - 1.0;
    double pz = (double)(n / 9) - 1.0;
    GLdouble vertex[][3] = {
        {px, py, pz},
        {px + size, py, pz},
        {px + size, py + size, pz},
        {px, py + size, pz},
        {px, py, pz + size},
        {px + size, py, pz + size},
        {px + size, py + size, pz + size},
        {px, py + size, pz + size}};
    int face[][4] = {
        {4, 5, 1, 0},
        {1, 5, 6, 2},
        {5, 4, 7, 6},
        {4, 0, 3, 7},
        {0, 1, 2, 3},
        {3, 2, 6, 7}};
    int edge[][2] = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 4},
        {0, 4},
        {1, 5},
        {2, 6},
        {3, 7}};
    GLdouble color[][3] = {
        {1.0, 1.0, 0.0}, //下黄色
        {0.0, 1.0, 0.0}, //右緑
        {1.0, 0.5, 0.0}, //前オレンジ
        {0.0, 0.0, 1.0}, //左青
        {1.0, 0.0, 0.0}, //後ろ赤
        {1.0, 1.0, 1.0}, //上白
        {0.1, 0.1, 0.1}};
    /* 図形の色   */
    int c = n % 6;

    /* 図形の描画 */
    glBegin(GL_QUADS);

    for (int j = 0; j < 6; ++j)
    {
        //printf("描画colorlist[%2d][%2d]=%2d\n", n, j, colorlist[n][j]);
        glColor3dv(color[colorlist[n][j]]);
        for (int i = 0; i < 4; ++i)
        {
            glVertex3dv(vertex[face[j][i]]);
        }
    }
    glEnd();
    /* 図形の描画 */
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 12; ++i)
    {
        glVertex3dv(vertex[edge[i][0]]);
        glVertex3dv(vertex[edge[i][1]]);
    }
    glEnd();
}
//
// ウィンドウ再描画時に呼ばれるコールバック関数
//

// アイドル時に呼ばれるコールバック関数
//
void idle(void)
{
    glutPostRedisplay();
    r[stat] += 1;
    if (r[stat] >= tmp + 90)
    {
        if (r[stat] >= 90)
            r[stat] = 0;
        facemove(stat, flag);
        stat = -1;
        glutIdleFunc(0);
    }
}

void display(void)
{
    // 画面をクリア（ピクセルデータとＺバッファの両方をクリア）
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 変換行列を記録
    glPushMatrix();

    // 光源位置を設定（モデルビュー行列の変更にあわせて再設定）
    float light0_position[] = {10.0, 10.0, 10.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    // 地面を描画
    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glColor3f(0.5, 0.8, 0.5);

    glVertex3f(5.0, 0.0, 5.0);
    glVertex3f(5.0, 0.0, -5.0);
    glVertex3f(-5.0, 0.0, -5.0);
    glVertex3f(-5.0, 0.0, 5.0);
    glEnd();

    // 変換行列を設定（物体のモデル座標系→カメラ座標系）
    //（物体が (0.0, 1.0, 0.0) の位置にあり、静止しているとする）
    glTranslatef(0.0, 1.0, 0.0);

    for (int i = 0; i < 27; i++)
    {
        glPushMatrix();
        if (flag == 3)
        {
            if (rlist[0][i])
            {
                glTranslated(+0.5, +0.5, 0.0);
                glRotated((double)r[0], 0.0, 0.0, 1.0);
                glTranslated(-0.5, -0.5, -0.0);
            }
            if (rlist[1][i])
            {
                glTranslated(0.0, +0.5, +0.5);
                glRotated((double)r[1], 1.0, 0.0, 0.0);
                glTranslated(0.0, -0.5, -0.5);
            }
        }
        if (flag == 2)
        {
            if (rlist[2][i])
            {
                glTranslated(+0.5, +0.5, 0.0);
                glRotated((double)r[0], 0.0, 0.0, 1.0);
                glTranslated(-0.5, -0.5, -0.0);
            }
            if (rlist[3][i])
            {
                glTranslated(0.0, +0.5, +0.5);
                glRotated((double)r[1], 1.0, 0.0, 0.0);
                glTranslated(0.0, -0.5, -0.5);
            }
        }
        if (flag == 1)
        {
            if (rlist[4][i])
            {
                glTranslated(+0.5, +0.5, 0.0);
                glRotated((double)r[0], 0.0, 0.0, 1.0);
                glTranslated(-0.5, -0.5, -0.0);
            }
            if (rlist[5][i])
            {
                glTranslated(0.0, +0.5, +0.5);
                glRotated((double)r[1], 1.0, 0.0, 0.0);
                glTranslated(0.0, -0.5, -0.5);
            }
        }

        cube(i);
        glPopMatrix();
    }
    // 変換行列を復元
    glPopMatrix();

    // バックバッファに描画した画面をフロントバッファに表示
    glutSwapBuffers();
}

// ウィンドウサイズ変更時に呼ばれるコールバック関数
//
void reshape(int w, int h)
{
    // ウィンドウ内の描画を行う範囲を設定（ウィンドウ全体に描画するように設定）
    glViewport(0, 0, w, h);

    // カメラ座標系→スクリーン座標系への変換行列を設定
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (double)w / h, 1, 500);
}
//
// マウスクリック時に呼ばれるコールバック関数
//
void mouse(int button, int state, int mx, int my)
{
    // 右ボタンが押されたらドラッグ開始のフラグを設定
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
        drag_mouse_l = 1;
    // 右ボタンが離されたらドラッグ終了のフラグを設定
    else if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP))
        drag_mouse_l = 0;

    // 右ボタンが押されたらドラッグ開始のフラグを設定
    if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN))
        drag_mouse_r = 1;
    // 右ボタンが離されたらドラッグ終了のフラグを設定
    else if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_UP))
        drag_mouse_r = 0;
    // 現在のマウス座標を記録
    last_mouse_x = mx;
    last_mouse_y = my;
}

//
// マウスドラッグ時に呼ばれるコールバック関数
//
void motion(int mx, int my)
{
    // 左ボタンのドラッグ中であれば、マウスの移動量に応じて視点を移動する
    if (drag_mouse_l == 1)
    {

        // マウスの縦移動に応じてカメラの距離を変化
        float delta_dist = (my - last_mouse_y) * 1.0;

        // 現在の変換行列（カメラの向き）を取得
        float m[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, m);

        // 変換行列を初期化して、カメラ移動分の平行移動行列を設定
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0, 0.0, -delta_dist);

        // 右からこれまでの変換行列をかける
        glMultMatrixf(m);
    }

    // 右ボタンのドラッグ中であれば、マウスの移動量に応じて視点を回転する
    if (drag_mouse_r == 1)
    {

        // マウスの横移動に応じてＹ軸を中心に回転
        float delta_yaw = (mx - last_mouse_x) * 1.0;
        // 現在の変換行列の右側に、今回の回転変換をかける
        glMatrixMode(GL_MODELVIEW);
        glRotatef(delta_yaw, 0.0, 1.0, 0.0);
    }

    // 右ボタンのドラッグ中であれば、マウスの移動量に応じて視点を回転する
    if (drag_mouse_r == 1)
    {

        // マウスの縦移動に応じてＸ軸を中心に回転
        float delta_pitch = (my - last_mouse_y) * 1.0;

        // 現在の変換行列を取得
        float m[16];
        float tx, ty, tz;
        glGetFloatv(GL_MODELVIEW_MATRIX, m);

        // 現在の変換行列の平行移動成分を記録
        tx = m[12];
        ty = m[13];
        tz = m[14];

        // 現在の変換行列の平行移動成分を０にする
        m[12] = 0.0f;
        m[13] = 0.0f;
        m[14] = 0.0f;

        // 変換行列を初期化
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // カメラの平行移動行列を設定
        glTranslatef(tx, ty, tz);

        // 右側に、今回の回転変換をかける
        glRotatef(delta_pitch, 1.0, 0.0, 0.0);

        // さらに、右側に、もとの変換行列から平行移動成分をとり除いたものをかける
        glMultMatrixf(m);
    }

    // 今回のマウス座標を記録
    last_mouse_x = mx;
    last_mouse_y = my;

    // 再描画の指示を出す（この後で再描画のコールバック関数が呼ばれる）
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
    case 'Q':
    case '\033': /* '\033' は ESC の ASCII コード */
        exit(0);
    case 'c':
        if (stat == -1)
        {
            stat = 0;
            flag = 3;
            tmp = r[stat];
            /* アニメーション開始 */
            glutIdleFunc(idle);
        }
        break;
    case 'x':
        if (stat == -1)
        {
            stat = 0;
            flag = 2;
            tmp = r[stat];
            /* アニメーション開始 */
            glutIdleFunc(idle);
        }
        break;
    case 'z':
        if (stat == -1)
        {
            stat = 0;
            flag = 1;
            tmp = r[stat];
            /* アニメーション開始 */
            glutIdleFunc(idle);
        }
        break;

    case 'v':
        if (stat == -1)
        {
            stat = 1;
            flag = 3;
            tmp = r[stat];
            /* アニメーション開始 */
            glutIdleFunc(idle);
        }
        break;
    case 'f':
        if (stat == -1)
        {
            stat = 1;
            flag = 2;
            tmp = r[stat];
            /* アニメーション開始 */
            glutIdleFunc(idle);
        }
        break;
    case 'r':
        if (stat == -1)
        {
            stat = 1;
            flag = 1;
            tmp = r[stat];
            /* アニメーション開始 */
            glutIdleFunc(idle);
        }
        break;

    default:
        break;
    }
}

//
// 環境初期化関数
//
void initEnvironment(void)
{

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    // 光源を作成する
    float light0pos[] = {10.0, 10.0, 10.0, 1.0};
    float light0_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    float light0_specular[] = {1.0, 1.0, 1.0, 1.0};
    float light0_ambient[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glEnable(GL_LIGHT0);
    // 光源計算を有効にする
    glEnable(GL_LIGHTING);
    // 物体の色情報を有効にする
    glEnable(GL_COLOR_MATERIAL);

    // 変換行列を初期化
    //glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -15.0);
    glRotatef(30.0, 1.0, 0.0, 0.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
}

int main(int argc, char **argv)
{
    // GLUTの初期化
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(WindowTitle);

    // コールバック関数の登録
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    // 環境初期化
    initEnvironment();
    // GLUTのメインループに処理を移す
    glutMainLoop();
    // プログラムを終了
    return 0;
}