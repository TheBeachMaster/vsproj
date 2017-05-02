<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Transact.aspx.cs" Inherits="UserAuth1.Transact" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Goods Page</title>
    <link href="Contents/bootstrap-theme.min.css" rel="stylesheet" />
    <link href="Contents/bootstrap.min.css" rel="stylesheet" />
    <script src="Scripts/bootstrap.js"></script>
    <script src="Scripts/bootstrap.min.js"></script>
    <script src="Scripts/jQuery.js"></script>
    <script src="Scripts/npm.js"></script>
</head>
<body>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/js/bootstrap.min.js"></script>
    <form id="form1" runat="server">
        <asp:ScriptManager ID="ScriptManager1" runat="server">
    </asp:ScriptManager>
        <div class="container">
            <asp:CheckBoxList ID="ItemsList" runat="server">
                
                    <asp:ListItem Value="10"> Chapo Ndengu </asp:ListItem>
                    <asp:ListItem Value="20"> Mayai Frai </asp:ListItem>
                    <asp:ListItem Value="30"> Nduvia + Escort </asp:ListItem>
                    <asp:ListItem Value="40"> Uji Maziwa </asp:ListItem>
                    <asp:ListItem Value="50"> Ugali Skuma </asp:ListItem>
                    <asp:ListItem Value="60"> Rice Nyama </asp:ListItem>
            </asp:CheckBoxList>
            <p>
                <asp:Label ID="Label2" runat="server"></asp:Label>
            </p>
        </div>
        <div class="container btn-group">
            <asp:Button Text="Check Total" runat="server" CssClass="btn btn-lg btn-info" OnClick="GetTotals" />
            <asp:Button Text="Pay Items" runat="server" CssClass="btn btn-lg btn-primary" OnClick="LaunchPayModal" />
        </div>

            <!-- Bootstrap Modal Dialog -->
<div class="modal fade" id="transactModal" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <asp:UpdatePanel ID="upModal" runat="server" ChildrenAsTriggers="false" UpdateMode="Conditional">
            <ContentTemplate>
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                        <h4 class="modal-title"><asp:Label ID="lblModalTitle" runat="server" Text=""></asp:Label></h4>
                    </div>
                    <div class="modal-body">
                        
                        <p>
                            Pay via M-PESA
                            </p>
                        <div class="container">
                            <input type="text" name="transact" value="" placeholder="Enter MPESA Code" size="15" />
                            <asp:Button ID="PayBtn" runat="server" Text="Sumbit Code" CssClass="btn btn-lg btn-primary" />
                        </div>
                        <asp:Label ID="Label1" runat="server" ></asp:Label>
                    </div>
                    <div class="modal-footer">
                        <button class="btn btn-info" data-dismiss="modal" aria-hidden="true">Close</button>
                    </div>
                </div>
            </ContentTemplate>
        </asp:UpdatePanel>
    </div>
</div>
    </form>


</body>
</html>
