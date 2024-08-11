using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;


namespace FinalRS
{
    public partial class ChangePass : Form
    {
        public SqlConnection conn;
        public SqlCommand cmd;
        public SqlDataAdapter adp;
        public DataSet ds;

        public void Connection()
        {
            conn = new SqlConnection(@"Data Source=.\SQLEXPRESS;AttachDbFilename=C:\Users\Kousik kundu\Documents\Visual Studio 2005\Projects\FinalRS\FinalRS\Database1.mdf;Integrated Security=True;User Instance=True");
        }
        public ChangePass()
        {
            InitializeComponent();
        }
         public ChangePass(string a,string b)
        {
            InitializeComponent();
            label1.Text = a.ToString();
            label5.Text = b.ToString();
        }

        private void btnChange_Click(object sender, EventArgs e)
        {
            Connection();
            conn.Open();            
            adp = new SqlDataAdapter("select * from tbUser", conn);
            ds = new DataSet();
            adp.Fill(ds, "login");
            int nFlag = 0;
            for (int nCount = 0; nCount < ds.Tables["login"].Rows.Count; nCount++)
            {
                if (label1.Text == ds.Tables["login"].Rows[nCount][2].ToString() && txtOldPassword.Text == ds.Tables["login"].Rows[nCount][3].ToString())
                {
                    nFlag = 1;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if (nFlag == 1)
            {
                if(textBox1.Text==textBox2.Text)
                MessageBox.Show("Want to Update.....");
            }
            else
                MessageBox.Show("Please enter same password.....");
            cmd = new SqlCommand("update tbUser set Password='"+textBox1.Text+"' where UserName='"+label1.Text+"'",conn);
            txtOldPassword.Text = "";
            textBox1.Text = "";
            textBox2.Text = "";
            cmd.ExecuteNonQuery();
            conn.Close();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            if (label5.Text == "Manager")
            {
                this.Hide();
                Manager f2 = new Manager(label1.Text);
                f2.Show();
            }
            else
            {
                this.Hide();
                User f2 = new User(label1.Text);
                f2.Show();
            }
        }
    }
}