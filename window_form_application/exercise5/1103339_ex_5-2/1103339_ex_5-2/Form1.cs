using System.Net;

namespace _1103339_ex_5_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string strMinute = "";
            if (DateTime.Now.Minute > 50) strMinute = "50";
            else if (DateTime.Now.Minute > 40) strMinute = "40";
            else if (DateTime.Now.Minute > 30) strMinute = "30";
            else if (DateTime.Now.Minute > 20) strMinute = "20";
            else if (DateTime.Now.Minute > 10) strMinute = "10";
            else strMinute = "00";
            string mapURL = String.Format(
               "https://www.cwb.gov.tw/Data/satellite/LCC_IR1_CR_2750/LCC_IR1_CR_2750-{0}-{1}-{2}-{3}-{4}.jpg",
               DateTime.Now.Year,
               DateTime.Now.Month.ToString("00"),
               DateTime.Now.Day.ToString("00"),
               (DateTime.Now.Hour - 1).ToString("00"),
               strMinute);
            pictureBox1.ImageLocation = mapURL;
            pictureBox1.ClientSize = new Size(400, 430);

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.AutoSize = true;
            this.AutoSizeMode = AutoSizeMode.GrowAndShrink;
            pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
        }
    }
}