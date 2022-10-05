using System.ComponentModel.Design;
using System.Configuration;
using System.Globalization;
using System.Net.NetworkInformation;

namespace Assignment2
{
    public partial class Form1 : Form
    {
        int[,] matrix = new int[3, 3];
        const int boxSize = 100;
        const int paddings = 50;
        int[] winner_line = { 0, 0, 8 };
        bool onPlay = true;
        
        Rectangle[] rects = new Rectangle[9];
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            init();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g1 = this.CreateGraphics();
            Pen p1 = new Pen(Color.Black, 5);
            g1.DrawRectangles(p1, rects);
            Pen p2 = new Pen(Color.Blue, 5);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (matrix[i, j] == 1)
                        g1.DrawEllipse(p2, rects[i * 3 + j].X + 15, rects[i * 3 + j].Y + 15, 70, 70);
                    else if (matrix[i,j] == -1)
                    {
                        g1.DrawLine(p2, new Point(rects[i * 3 + j].X + 15, rects[i * 3 + j].Y + 15), new Point(rects[i * 3 + j].X + 85, rects[i * 3 + j].Y + 85));
                        g1.DrawLine(p2, new Point(rects[i * 3 + j].X + 15, rects[i * 3 + j].Y + 85), new Point(rects[i * 3 + j].X + 85, rects[i * 3 + j].Y + 15));
                    }
                }
            }
            if (winner_line[0] == 1)
            {
                Pen p3 = new Pen(Color.Red, 5);
                g1.DrawLine(p3, new Point(rects[winner_line[1]].X +50, rects[winner_line[1]].Y + 50), new Point(rects[winner_line[2]].X + 50, rects[winner_line[2]].Y + 50));
            }
        }



        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            bool playValid = false;
            if(onPlay)
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (rects[i * 3 + j].Contains(e.Location) && matrix[i,j] == 0)
                        {
                            matrix[i, j] = 1;
                            playValid = true;
                        }
                    }
                }
                Invalidate();
            }
            if(playValid)
            {
                if (checkWin() == 1)
                    return;
                int a = bestMove();
                a -= 100;
                matrix[a / 10, a % 10] = -1;
                Invalidate();
                checkWin();
            }
        }

        private int checkWin()
        {
            dynamic m = matrix;
            for(int i = 0; i < 3; i++)
            {
                if (m[i,0]!=0 && m[i, 0] == m[i, 1] && m[i, 1] == m[i, 2])
                {
                    winner_line[0] = 1;
                    winner_line[1] = i * 3;
                    winner_line[2] = i * 3 + 2;
                }
                if (m[0,i] != 0 && m[0,i] == m[1,i] && m[1, i] == m[2,i])
                {
                    winner_line[0] = 1;
                    winner_line[1] = i;
                    winner_line[2] = 6+i;
                }
            }
            if (m[0,0] != 0 && m[0,0] == m[1, 1] && m[1, 1] == m[2, 2])
            {
                winner_line[0] = 1;
                winner_line[1] = 0;
                winner_line[2] = 8;
            }
            if (m[2,0] != 0 && m[2, 0] == m[1, 1] && m[1, 1] == m[0, 2])
            {
                winner_line[0] = 1;
                winner_line[1] = 2;
                winner_line[2] = 6;
            }

            if (winner_line[0]==1)
            {
                onPlay = false;
                label2.Text = "Winner: " + ((matrix[winner_line[1] / 3, winner_line[1] % 3] == 1) ? "User" : "Computer");
                Invalidate();
            }

            int avail = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    avail += matrix[i, j] == 0 ? 1 : 0;
                }
            }
            if (avail == 0)
            {
                label2.Text = "Draw!";
                onPlay = false;
                return 0;
            }

            return winner_line[0];
        }

        private void rToolStripMenuItem_Click(object sender, EventArgs e)
        {
            init();
        }

        private void init()
        {
            onPlay = true;
            winner_line[0] = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrix[i, j] = 0; //init
                    rects[i * 3 + j] = new Rectangle(10 + boxSize * i, paddings + boxSize * j, boxSize, boxSize);
                }
            }
            Invalidate();
        }

        int[,] mat;

        private int bestMove()
        {
            mat = matrix;
            int axiom;
            int mx = int.MinValue, mxr = 0;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if (mat[i, j] == 0)
                    {
                        mat[i, j] = -1;
                        axiom = checkAxiom();
                        if (axiom == 0)
                        {
                            int a = dfs(1);
                            if (a > 0)
                                return 100 + i * 10 + j;
                            else
                            {
                                if(mx < a)
                                {
                                    mx = a;
                                    mxr = 100 + i * 10 + j;
                                }
                            }

                        }
                        else if (axiom == -1)
                        {
                            return 100 + i * 10 + j;
                        }

                        mat[i, j] = 0;
                    }
                }
            }
            return mxr;
        }

        private int dfs(int c)
        {
            int axiom = 0, w= 0, d=  0, l = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (mat[i,j] == 0)
                    {
                        mat[i, j] = (c % 2 == 0) ? -1 : 1;
                        axiom = checkAxiom();
                        if (axiom == 0)
                        {
                            int a = dfs(c + 1);
                            if(a >= 100) // draws
                            {
                                d += a / 100;
                            }
                            l = Math.Min(-l, a);
                            w = Math.Max(w, a);
                        }
                        else if(axiom == -1)
                        {
                            w++;
                        }
                        else if(axiom == 1)
                        {
                            l--;
                        }

                        mat[i, j] = 0;
                    }
                }
            }
            if(c%2 == 0)
            {
                if (w > 0) return w;
                if (d > 0) return d*100;
                if (l < 0) return l;
            }
            else
            {
                if (l < 0) return l;
                if (d > 0) return d * 100;
                if (w > 0) return w;
            }

            return 0;
        }

        private int checkAxiom()
        {
            dynamic m = mat;
            for (int i = 0; i < 3; i++)
            {
                if (m[i, 0] != 0 && m[i, 0] == m[i, 1] && m[i, 1] == m[i, 2])
                {
                    return m[i, 0];
                }
                if (m[0, i] != 0 && m[0, i] == m[1, i] && m[1, i] == m[2, i])
                {
                    return m[0, i];
                }
            }
            if (m[0, 0] != 0 && m[0, 0] == m[1, 1] && m[1, 1] == m[2, 2])
            {
                return m[0, 0];
            }
            if (m[2, 0] != 0 && m[2, 0] == m[1, 1] && m[1, 1] == m[0, 2])
            {
                return m[1, 1];
            }
            return 0;
        }
    }
}