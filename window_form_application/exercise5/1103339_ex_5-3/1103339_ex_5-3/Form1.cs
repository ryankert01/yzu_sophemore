namespace _1103339_ex_5_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void loadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                String s = openFileDialog1.FileName;
                pictureBox1.Image = new Bitmap(s);
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.AutoSize = true;
            this.AutoSizeMode = AutoSizeMode.GrowAndShrink;
            pictureBox1.SizeMode = PictureBoxSizeMode.AutoSize;
            openFileDialog1.Filter = "圖檔(*.BMP,*.JPG,*.GIF)|*.BMP;*.JPG;*.GIF|所有檔案(*.*)|*.*";

        }
    }
}