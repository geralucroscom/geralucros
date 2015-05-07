<?php

/**
 * @file
 * Contains the slider pro style plugin.
 */

/**
 * Style plugin to render views as slider pro instance.
 *
 * @ingroup views_style_plugins
 */
class slider_pro_style_plugin extends views_plugin_style {

  /**
   * Provide default options.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['slider_pro'] = array('default' => array());

    return $options;
  }

  /**
   * Adds Slider Pro configuration form options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Check if fields have been added.  Table style plugin will set
    // error_markup if fields are not added.
    // @see views_plugin_style::options_form()
    if (isset($form['error_markup'])) {
      return;
    }

    $field_names = $this->display->handler->get_field_labels();

    $form['slider_pro'] = array(
      '#type' => 'fieldset',
      '#title' => t('Slider Pro settings'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );

    $form['slider_pro']['width'] = array(
      '#title' => t('Width'),
      '#type' => 'textfield',
      '#default_value' => isset($this->options['slider_pro']['width']) ? $this->options['slider_pro']['width'] : '100%',
      '#description' => t('The width of the slider. Eg 200px or 50%'),
      '#required' => TRUE,
    );

    $form['slider_pro']['height'] = array(
      '#title' => t('Height'),
      '#type' => 'textfield',
      '#default_value' => isset($this->options['slider_pro']['height']) ? $this->options['slider_pro']['height'] : '200px',
      '#description' => t('The height of the slider. Eg 200px or 50%'),
      '#required' => TRUE,
    );

    $form['slider_pro']['orientation'] = array(
      '#title' => t('Orientation'),
      '#type' => 'select',
      '#options' => array('horizontal' => t('Horizontal'), 'vertical' => t('Vertical')),
      '#default_value' => isset($this->options['slider_pro']['orientation']) ? $this->options['slider_pro']['orientation'] : 'horizontal',
      '#description' => t('Indicates whether the slides will be arranged horizontally or vertically.'),
      '#required' => TRUE,
    );

    $form['slider_pro']['buttons'] = array(
      '#title' => t('Buttons'),
      '#type' => 'select',
      '#options' => array(0 => t('No'), 1 => t('Yes')),
      '#default_value' => isset($this->options['slider_pro']['buttons']) ? $this->options['slider_pro']['buttons'] : 0,
      '#description' => t('Indicates whether the buttons will be created.'),
      '#required' => TRUE,
    );

    $form['slider_pro']['transition'] = array(
      '#title' => t('Transition'),
      '#type' => 'select',
      '#options' => array(0 => t('Slide'), 1 => t('Fade')),
      '#default_value' => isset($this->options['slider_pro']['transition']) ? $this->options['slider_pro']['transition'] : 0,
      '#description' => t('Indicates which transition will be used.'),
      '#required' => TRUE,
    );

    $form['slider_pro']['arrows'] = array(
      '#title' => t('Arrows'),
      '#type' => 'select',
      '#options' => array(0 => t('No'), 1 => t('Yes')),
      '#default_value' => isset($this->options['slider_pro']['arrows']) ? $this->options['slider_pro']['arrows'] : 0,
      '#description' => t('Indicates whether the arrow buttons will be created..'),
      '#required' => TRUE,
    );

    $form['slider_pro']['fields_on_slide'] = array(
      '#title' => t('Fields on slide'),
      '#type' => 'checkboxes',
      '#options' => $field_names,
      '#default_value' => isset($this->options['slider_pro']['fields_on_slide']) ? $this->options['slider_pro']['fields_on_slide'] : array(),
      '#description' => t('Select which fields you want to display on the slider.'),
      '#required' => TRUE,
    );

    $form['slider_pro']['use_thumbnails'] = array(
      '#title' => t('Use thumbnails'),
      '#type' => 'checkbox',
      '#default_value' => isset($this->options['slider_pro']['use_thumbnails']) ? $this->options['slider_pro']['use_thumbnails'] : 0,
    );

    $form['slider_pro']['thumbnails'] = array(
      '#type' => 'fieldset',
      '#title' => t('Thumbnails'),
      '#collapsible' => FALSE,
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[slider_pro][use_thumbnails]"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['slider_pro']['thumbnails']['thumbnails_position'] = array(
      '#title' => t('Thumbnail position'),
      '#type' => 'select',
      '#options' => array('left' => t('Left'), 'right' => t('Right'), 'top' => t('Top'), 'bottom' => t('Bottom')),
      '#default_value' => isset($this->options['slider_pro']['thumbnails']['thumbnails_position']) ? $this->options['slider_pro']['thumbnails']['thumbnails_position'] : 0,
      '#required' => TRUE,
      '#description' => t('Sets the position of the thumbnail scroller.'),
    );

    $form['slider_pro']['thumbnails']['fields_on_thumbs'] = array(
      '#title' => t('Fields on thumb'),
      '#type' => 'checkboxes',
      '#options' => $field_names,
      '#default_value' => isset($this->options['slider_pro']['thumbnails']['fields_on_thumbs']) ? $this->options['slider_pro']['thumbnails']['fields_on_thumbs'] : array(),
      '#description' => t('Select which fields you want to display on the thumbs.'),
      '#required' => TRUE,
    );

    $form['slider_pro']['thumbnails']['width'] = array(
      '#title' => t('Width'),
      '#type' => 'textfield',
      '#default_value' => isset($this->options['slider_pro']['thumbnails']['width']) ? $this->options['slider_pro']['thumbnails']['width'] : '100px',
      '#description' => t('The width of each thumbnail. Eg 200px.'),
      '#required' => TRUE,
    );

    $form['slider_pro']['thumbnails']['height'] = array(
      '#title' => t('Height'),
      '#type' => 'textfield',
      '#default_value' => isset($this->options['slider_pro']['thumbnails']['height']) ? $this->options['slider_pro']['thumbnails']['height'] : '80px',
      '#description' => t('The height of each thumbnail. Eg 200px.'),
      '#required' => TRUE,
    );
  }

  /**
   * Add form validation for options.
   */
  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);

    // Form_error($form['slider_pro']['height'], 'test');
  }

  function validate() {
    parent::validate();
  }

}
