using System.Collections.Specialized;

namespace _1103339_ex_5_5
{
    public partial class Form1 : Form
    {
        List<Point> pt = new List<Point>();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            for(int i = 0; i < pt.Count(); i++)
            {
                e.Graphics.DrawString("(" + pt[i].X.ToString() + "," + pt[i].Y.ToString() + ")", this.Font, new SolidBrush(Color.Blue), pt[i].X, pt[i].Y);

            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                String s = saveFileDialog1.FileName;
                BinaryWriter outFile = new BinaryWriter(File.Open(s, FileMode.Create));
                outFile.Write(pt.Count());
                for(int i = 0; i < pt.Count(); i++)
                {
                    outFile.Write(pt[i].X);
                    outFile.Write(pt[i].Y);
                }
                outFile.Close();
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "點座標檔(*.ptf)|*.ptf";
            saveFileDialog1.Filter = "點座標檔(*.ptf)|*.ptf";
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            pt.Add(e.Location);
            Invalidate();
        }

        private void loadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                String s = openFileDialog1.FileName;
                if (!File.Exists(s)) return;
                BinaryReader inFile = new BinaryReader(File.Open(s, FileMode.Open));
                pt.Clear();
                int n = inFile.ReadInt32();
                for (int i = 0; i < n; i++)
                    pt.Add(new Point(inFile.ReadInt32(), inFile.ReadInt32()));
                Invalidate();
                inFile.Close();
            }
        }

        private void clearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            pt.Clear();
            Invalidate();
        }
    }
}