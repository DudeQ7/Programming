$path = 'C:\Users\DudeQ\Documents\Programming\cpp\Testowanie_oprogramowania\Testing\Google_test\Google_test.vcxproj'
$text = Get-Content -Raw -Path $path
$bad = '    <ClCompile Include="pch.cpp">`r`n      <PrecompiledHeader>Create</PrecompiledHeader>`r`n    </ClCompile>'
$good = @"
    <ClCompile Include="pch.cpp">
      <PrecompiledHeader>Create</PrecompiledHeader>
    </ClCompile>
"@
if ($text.Contains($bad)) {
    $text = $text.Replace($bad, $good.TrimEnd())
    Set-Content -Path $path -Value $text
    Write-Host 'fixed'
} else {
    Write-Host 'notfound'
}
