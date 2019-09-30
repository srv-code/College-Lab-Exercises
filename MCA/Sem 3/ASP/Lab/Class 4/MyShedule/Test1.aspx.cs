using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;
using System.Collections;


public partial class Test1 : System.Web.UI.Page {
    protected void Page_Load(object sender, EventArgs e) {

    }
    
    protected void Button_Submit_Click(object sender, EventArgs e) {
        ArrayList ls = new ArrayList();
        ls.Add(DateTime.Parse("Jan 11, 2019"));
 
        TextBox_Data.Text += ls.Contains(DateTime.Now);
        TextBox_Data.Text += ls.Contains(DateTime.Parse("Jan 11, 2019"));
    }
}