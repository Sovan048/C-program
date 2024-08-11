using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;


namespace Win_Data_Base
{

    public partial class Form1 : Form
    {
        public SqlConnection conn;
        public SqlCommand cmd;
        public SqlDataAdapter adp;
        public DataSet ds;
        public Form1()
        {
            InitializeComponent();
        }
        public void Connection()
        {
            conn = new SqlConnection(@"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\kousi\Desktop\Win_Data_Base\Win_Data_Base\Database1.mdf;Integrated Security=True");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "" || textBox2.Text != "")
            {
                Connection();
                conn.Open();
                cmd = new SqlCommand("insert into tbTest (A,B) values ('" + textBox1.Text + "','" + textBox2.Text + "')", conn);
                cmd.ExecuteNonQuery();
                MessageBox.Show("Are you sure to insert details ?");
                conn.Close();
                textBox2.Text = "";
                //txtUserName.Text = "";
                textBox1.Text = "";
            }
            else
            {
                MessageBox.Show("Enter All fields::");
            }

        }
    }
}
