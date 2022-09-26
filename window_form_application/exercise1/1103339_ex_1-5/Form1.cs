using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1103339_ex_1_5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            listBox1.Items.AddRange(
                new Object[]
                {
                    "滑鼠",
                    "鍵盤",
                    "網卡",
                    "螢幕",
                    "音效卡"
                });
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Add(textBox1.Text);
            textBox1.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(textBox2.Text == "")
            {
                listBox1.Items.Add(textBox1.Text);
            } 
            else
            {
                int idx = Convert.ToInt32(textBox2.Text);
                listBox1.Items.Insert(idx, textBox1.Text);
            }
            textBox1.Clear();
            label1.Text = "目前位置：" + listBox1.SelectedIndex;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if(textBox2.Text != "")
            {
                int idx = Convert.ToInt32(textBox2.Text);
                if(idx >= 0 && idx < listBox1.Items.Count)
                listBox1.Items.RemoveAt(idx);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            string searchString = textBox1.Text;
            int idx = listBox1.FindString(searchString);

            if (idx != -1)
                listBox1.SetSelected(idx, true);
            else
                MessageBox.Show("目前的ListBox中並沒有要查尋的「" + searchString + "」");
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            label1.Text = "目前位置：" + listBox1.SelectedIndex;
        }
    }
}
