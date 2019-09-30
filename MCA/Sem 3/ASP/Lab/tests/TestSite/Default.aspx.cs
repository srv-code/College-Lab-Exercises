using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
        Response.Write("["+DateTime.Now.Millisecond+"]");
    }

    protected void Button1_Click(object sender, EventArgs e) {
        Response.Write("Button1_Click invoked, ");
    }

    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e) {
        // Response.Write("item selected");
        // System.Diagnostics.Debug.WriteLine("hi");
    }
    protected void TextBox1_TextChanged(object sender, EventArgs e) {
        Response.Write("[TextBox1_TextChanged invoked]");
    }

    protected void Button1_Command(object sender, CommandEventArgs e) {
        System.Diagnostics.Debug.WriteLine("Button1_Command invoked [CommandArgument={0}, CommandName={1}], ",
            e.CommandArgument, e.CommandName);

        // Response.Output.WriteLine("Button1_Command invoked [CommandArgument={0}, CommandName={1}], ",
            // e.CommandArgument, e.CommandName);
    }
}