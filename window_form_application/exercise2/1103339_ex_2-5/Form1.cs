using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1103339_ex_2_5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Text = DateTime.Now.ToString();
            label1.Text += "\n Year: " + DateTime.Now.Year.ToString();
            label1.Text += "\n Month: " + DateTime.Now.Month.ToString();
            label1.Text += "\n Day: " + DateTime.Now.Day.ToString();
            label1.Text += "\n Hour: " + DateTime.Now.Hour.ToString();
            label1.Text += "\n Minute: " + DateTime.Now.Minute.ToString();
            label1.Text += "\n Second: " + DateTime.Now.Second.ToString();
        }

        private void Form1_Activated(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer1.Interval = 1000;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            label1.Text = DateTime.Now.ToString();

        }
    }
}
