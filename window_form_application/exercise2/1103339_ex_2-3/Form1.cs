using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1103339_ex_2_3
{
    public partial class Form1 : Form
    {

        private bool nonNumberEntered = false;
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            nonNumberEntered = false;
            if(e.KeyCode < Keys.D0 || e.KeyCode > Keys.D9)
            {
                if(e.KeyCode < Keys.NumPad0 || e.KeyCode > Keys.NumPad9)
                {
                    nonNumberEntered = true;
                }
            }
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(nonNumberEntered)
            {
                e.Handled = true;
                label2.Text = e.KeyChar + " is not a digit. Please input a digit.";
            }
            else
            {
                label2.Text = e.KeyChar + " is Okay.";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(Control.IsKeyLocked(Keys.CapsLock))
            {
                label3.Text = "CapsLock ON\r\n";
            }
            else
            {
                label3.Text = "CapsLock OFF\r\n";
            }
            if(Control.IsKeyLocked(Keys.NumLock))
            {
                label3.Text += "NumLock ON";
            }
            else
            {
                label3.Text += "NumLock OFF";
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.ActiveControl = textBox1;
        }
    }
}
