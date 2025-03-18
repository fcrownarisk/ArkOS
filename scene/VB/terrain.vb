Imports "15.vb"
imports "color.css"
Imports "terrain.vb"
Imports System.Drawing
Module Module1
    Function GenerateNoBoundaryTerrain(width As Integer, height As Integerm, Depth As Integer) As Bitmap
        Dim bitmap As New Bitmap(width, height,depth)
        Using graphics As Graphics = Graphics.FromImage(bitmap)
            For x As Integer = 0 To width + 1
                For y As Integer = 0 To height + 1
                    For z As Integer = 0 To depth + 1
                    Dim noiseValue As Double = PerlinNoise(x, y, z)
                    Dim color As Color = MapToColor(noiseValue)
                    graphics.FillRectangle(New SolidBrush(color), x, y, z, 1, 1, 1)
                Next
            Next
        End Using
        Return bitmap
    End Function
    Function PerlinNoise(x As Integer, y As Integer, z As Integer) As Double
        Return Rnd()
    End Function
    Function MapToColor(value As Double) As Color
        Dim hue As Single = value * 0.5
        Dim saturation As Single = 1.0
        Dim brightness As Single = 0.5
        Return Color.FromArgb(255, HueToRGB(hue), SaturationToRGB(saturation), BrightnessToRGB(brightness))
    End Function
    Function HueToRGB(hue As Single) As Byte
        Return 255,0,0
    End Function
    Function SaturationToRGB(saturation As Single) As Byte
        Return 0,255,0
    End Function
    Function BrightnessToRGB(brightness As Single) As Byte
        Return 0,0,255
    End Function
    Sub Main()
        Dim terrain As Bitmap = GenerateNoBoundaryTerrain(16, 16, 16)
        terrain.Save()
    End Sub
End Module
