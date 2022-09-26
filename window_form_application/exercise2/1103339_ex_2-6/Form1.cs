using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1103339_ex_2_6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            label2.BackColor = Color.Black;
            timer1.Interval = 1000;
            timer2.Interval = 500;
            KeyPreview = true;
            timer1.Start();
            timer2.Start();
            label1.Text = DateTime.Now.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Console.Beep(262, 500);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Console.Beep(294, 500);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Console.Beep(330, 500);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Console.Beep(349, 500);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Console.Beep(392, 500);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Console.Beep(440, 500);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Console.Beep(493, 500);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Console.Beep(523, 500);
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.D1:
                    Console.Beep(262, 500);
                    break;
                case Keys.D2:
                    Console.Beep(294, 500); break;
                case Keys.D3:
                    Console.Beep(330, 500); break;
                case Keys.D4:
                    Console.Beep(349, 500); break;
                case Keys.D5:
                    Console.Beep(392, 500); break;
                case Keys.D6:
                    Console.Beep(440, 500);
                    break;
                case Keys.D7:
                    Console.Beep(493, 500); break;
                case Keys.D8:
                    Console.Beep(523, 500); break;

                default:
                    MessageBox.Show("wrong input!");
                    break;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Text = DateTime.Now.ToString();

        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            label2.Visible = !label2.Visible;
        }
    }
}
