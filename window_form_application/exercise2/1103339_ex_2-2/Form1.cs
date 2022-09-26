using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1103339_ex_2_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.ForeColor = Color.Red;
            textBox1.BackColor = Color.Black;
            textBox2.ForeColor = Color.Red;
            textBox2.BackColor = Color.White;
        }

        private void textBox1_Enter(object sender, EventArgs e)
        {
            if(textBox1.Text != String.Empty)
            {
                textBox1.ForeColor = Color.Red;
                textBox1.BackColor = Color.Black;
            }
        }

        private void textBox1_Leave(object sender, EventArgs e)
        {
            textBox1.ForeColor = Color.Black;
            textBox1.BackColor = Color.White;
        }

        private void textBox2_Enter(object sender, EventArgs e)
        {
            if(textBox2.Text != string.Empty)
            {
                textBox2.ForeColor = Color.Red;
                textBox2.BackColor = Color.White;
            }
        }

        private void textBox2_Leave(object sender, EventArgs e)
        {
            textBox2.ForeColor = Color.Black;
            textBox2.BackColor = Color.White;
        }
    }
}
