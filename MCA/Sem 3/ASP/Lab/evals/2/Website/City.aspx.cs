﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class City : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
		Label_CityName.Text = "City is " + Request.QueryString["name"];
    }
}