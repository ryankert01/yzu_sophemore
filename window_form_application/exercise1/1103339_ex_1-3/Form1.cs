using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1103339_ex_1_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            Size = new Size(Convert.ToInt32(numericUpDown1.Value), Convert.ToInt32(numericUpDown2.Value));
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            Size = new Size(Convert.ToInt32(numericUpDown1.Value), Convert.ToInt32(numericUpDown2.Value));
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Size = new Size(Convert.ToInt32(numericUpDown3.Value), Convert.ToInt32(numericUpDown4.Value));
        }
    }
}
