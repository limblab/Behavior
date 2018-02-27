<?xml version="1.0" encoding="utf-8" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  
  <xsl:template match="/LabList">
    <html>
      <body>
        <h2>Lab Configuration Settings</h2>
        <table border="1">
          <tr bgcolor="#9acd32">
            <th>Parameter</th>
            <th>Value</th>
          </tr>
          <xsl:for-each select="LabConfig">
            <tr>
              <td colspan="3" style="background-color: #ddd; font-weight: bold; text-align: center;">
                Lab <xsl:value-of select="attribute::lab"/>
              </td>
            </tr>
            <xsl:for-each select="LabParamList/LabParam">
            <tr>
              <td><xsl:value-of select="Block"/> : <xsl:value-of select="Name"/></td>
              <td style="text-align: right;"><xsl:value-of select="Value"/></td>
            </tr>
            </xsl:for-each>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="/CursorDefs">
    <html>
      <body>
        <h2>Cursor Definitions</h2>
        <table border="1">
          <tr bgcolor="#9acd32">
            <th>Name</th>
            <th>File</th>
            <th>Origin</th>
          </tr>
          <xsl:for-each select="CursorDef">
            <tr>
              <td><xsl:value-of select="Name"/></td>
              <td><xsl:value-of select="File"/></td>
              <td>(<xsl:value-of select="X"/>, <xsl:value-of select="X"/>)</td>
            </tr>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>
  
</xsl:stylesheet>