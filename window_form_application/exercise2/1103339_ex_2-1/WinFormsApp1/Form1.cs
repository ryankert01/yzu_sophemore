using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("Form1 Click 事件\r\n");
        }

        private void textBox1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("TextBox Click 事件\r\n");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "Form1 load 事件\r\n";
        }

        private void Form1_Activated(object sender, EventArgs e)
        {
            textBox1.AppendText("Form1 Activated 事件\r\n");
        }
    }
}
