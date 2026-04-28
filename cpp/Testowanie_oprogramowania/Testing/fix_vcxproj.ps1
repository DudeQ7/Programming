$path = 'C:\Users\DudeQ\Documents\Programming\cpp\Testowanie_oprogramowania\Testing\Google_test\Google_test.vcxproj'
$text = Get-Content -Raw -Path $path
$old = '    <ClCompile Include="pch.cpp" />'
$new = '    <ClCompile Include="pch.cpp">`r`n      <PrecompiledHeader>Create</PrecompiledHeader>`r`n    </ClCompile>'
if ($text.Contains($old)) {
    $text = $text.Replace($old, $new)
    Set-Content -Path $path -Value $text
    Write-Host 'patched'
} else {
    Write-Host 'nochange'
}
