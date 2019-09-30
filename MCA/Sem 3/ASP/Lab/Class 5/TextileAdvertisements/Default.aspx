<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Textile  Industries</title>
	<link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">
		<div id="div_ad1">
			<asp:AdRotator ID="AdRotator_TextileIndustry1" runat="server"
				AdvertisementFile="~/App_Data/ads/textile.xml"
				KeywordFilter="Industry1" 
				Height="100" Width="200" />
		</div>
		<div id="div_ad2">
			<asp:AdRotator ID="AdRotator_TextileIndustry2" runat="server"
				AdvertisementFile="~/App_Data/ads/textile.xml"
				KeywordFilter="Industry2" 
				Height="100" Width="200" />
		</div>
    </form>
</body>
</html>
