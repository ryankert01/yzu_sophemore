using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1103339_ex_1_4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            double a = double.Parse(textBox1.Text);
            double b = double.Parse(textBox2.Text);
            double c = a + b;
            label5.Text = c.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double a = double.Parse(textBox3.Text);
            double b = double.Parse(textBox4.Text);
            double c = a - b;
            label6.Text = c.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            double a = double.Parse(textBox5.Text);
            double b = double.Parse(textBox6.Text);
            double c = a * b;
            label7.Text = c.ToString();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            double a = double.Parse(textBox7.Text);
            double b = double.Parse(textBox8.Text);
            double c = a / b;
            label10.Text = c.ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            double w = double.Parse(textBox9.Text);
            double h = double.Parse(textBox10.Text);
            h /= 100;
            double bmi = w / Math.Pow(h, 2);
            label9.Text = bmi.ToString();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            double start = double.Parse(textBox11.Text);
            double end = double.Parse(textBox12.Text);
            double cnt = double.Parse(textBox13.Text);
            double res = 0;
            for(double i = start; i <= end; i += cnt)
            {
                res += i;
            }
            label16.Text = res.ToString();
        }
    }
}
