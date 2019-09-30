using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class PictureSelection : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        ImageButton_Big.ImageUrl = ((ImageButton)sender).ImageUrl;
    }
    protected void ImageButton_Big_Click(object sender, ImageClickEventArgs e)
    {
        ImageButton_Big.ImageUrl = "";
    }
}