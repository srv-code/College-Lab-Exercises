using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        // Label1.Text = DateTime.Now.ToString("T");
        TextBox1.Text = "sender=" + sender + ", e=" + e;
    }
    protected void LinkButton1_Click(object sender, EventArgs e)
    {
        TextBox1.Text = "sender="+sender+", e="+e;
        
    }
    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        TextBox1.Text = "sender=" + sender + ", e=" + e;
    }
}