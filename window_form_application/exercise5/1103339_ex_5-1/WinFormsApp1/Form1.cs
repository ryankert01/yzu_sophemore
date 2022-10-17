namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void domainUpDown1_SelectedItemChanged(object sender, EventArgs e)
        {
            switch(domainUpDown1.SelectedIndex)
            {
                case 0:
                    pictureBox1.SizeMode = PictureBoxSizeMode.Normal;
                    break;
                case 1:
                    pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
                    break;
                case 2:
                    pictureBox1.SizeMode = PictureBoxSizeMode.AutoSize;
                    break;
                case 3:
                    pictureBox1.SizeMode = PictureBoxSizeMode.CenterImage;
                    break;
                case 4:
                    pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
                    break;

            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            domainUpDown1.SelectedIndex = 0;
            this.AutoSize = true;
            this.AutoSizeMode = AutoSizeMode.GrowAndShrink;
        }
    }
}