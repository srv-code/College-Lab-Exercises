using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
        Response.Write("[" + DateTime.Now.Millisecond + "]");
    }
    protected void Button1_Click(object sender, EventArgs e)
    {

    }
    protected void CustomValidator1_ServerValidate(object source, ServerValidateEventArgs args)
    {
        args.IsValid = int.Parse(args.Value) > 10;
        System.Diagnostics.Debug.WriteLine("args.Value=" + args.Value);
    }
}